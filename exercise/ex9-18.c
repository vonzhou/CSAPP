/*
 * 9.18
 *
 * mofaph@gmail.com
 *
 * 在书本的 569 页的最后一段，作者提到了一种非常聪明的边界标记的优化方法，能够使
 * 得在已分配块中不再需要脚部。
 *
 * 这个程序是对边界优化的一种尝试。以 8 个字节对齐，最小块也是 8 个字节。因此，可
 * 以使用最低的一位表示当前的块是否已分配，使用最低的第二位表示前一个块是否已分配。
 *
 * 这个程序其实就是书本的家庭作业 9.18，题目是：
 *
 * 9.9.12 节中的分配器要求每个块既有头部也有脚部，以实现常数时间的合并。修改分配
 * 器，使得空闲块需要头部和脚部，而已分配块只需要头部。
 *
 * unix> gcc -I../common ../common/csapp.c ../sample/ch09/memlib.c ex9-18.c t9-17.c -lpthread
 */

#include <stdio.h>

/* Basic constants and macros */
#define WSIZE 4                 /* Word and header/footer size (bytes) */
#define DSIZE 8                 /* Double word size (bytes) */
#define CHUNKSIZE (1<<12)       /* Extend heap by this amount (bytes) */

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)
#define GET_ALLOC_PREV(p) (GET(p) & 0x2)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp) ((char *)(bp) - WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

static char *heap_listp;

static void *extend_heap(size_t words);
static void *coalesce(void *bp);
static void *find_fit(size_t asize);
static void place(void *bp, size_t asize);

/* Extern functions from memlib.c */
extern void mem_init(void);
extern void *mem_sbrk(int incr);

int mm_init(void)
{
        /* Create the initial empty heap */
        heap_listp = mem_sbrk(2*WSIZE);
        if (heap_listp == (void *)-1)
                return -1;
        PUT(heap_listp + (0*WSIZE), PACK(WSIZE, 1)); /* Prologue header */
        PUT(heap_listp + (1*WSIZE), PACK(0, 3));     /* Epilogue header */
        heap_listp += WSIZE;

        /* Extend the empty heap with a free block of CHUNKSIZE bytes */
        if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
                return -1;
        return 0;
}

static void *extend_heap(size_t words)
{
        char *bp;
        size_t size;

        /* Allocate an even number of words to maintain aligment */
        size = (words % 2) ? (words+1) * WSIZE : words * WSIZE;
        bp = mem_sbrk(size);
        if ((long)bp == -1)
                return NULL;

        /* Initialize free block header/footer and the epilogue header */
        int prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        PUT(HDRP(bp), PACK(size, prev_alloc)); /* Free block header */
        PUT(FTRP(bp), PACK(size, prev_alloc)); /* Free block footer */
        PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));  /* New epilogue header */

        /* Coalesce if the previous block was free */
        return coalesce(bp);
}

void mm_free(void *bp)
{
        size_t size;

        int prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        size = GET_SIZE(HDRP(bp));
        PUT(HDRP(bp), PACK(size, prev_alloc));
        PUT(FTRP(bp), PACK(size, prev_alloc));

        char *next_block = NEXT_BLKP(bp);
        int next_alloc = GET_ALLOC(HDRP(next_block));
        size = GET_SIZE(HDRP(next_block));
        PUT(HDRP(next_block), PACK(size, next_alloc));
        if (!next_alloc)
                PUT(FTRP(next_block), PACK(size, next_alloc));

        coalesce(bp);
}

static void *coalesce(void *bp)
{
        size_t prev_alloc = GET_ALLOC_PREV(HDRP(bp));
        size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
        size_t size = GET_SIZE(HDRP(bp));

        char *next_block;
        size_t next_size;

        if (prev_alloc && next_alloc)         /* Case 1 */
                return bp;

        else if (prev_alloc && !next_alloc) { /* Case 2 */
                size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }

        else if (!prev_alloc && next_alloc) { /* Case 3 */
                bp = PREV_BLKP(bp);
                size += GET_SIZE(HDRP(bp));
                prev_alloc = GET_ALLOC_PREV(HDRP(bp));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }

        else {                                /* Case 4 */
                size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(HDRP(NEXT_BLKP(bp)));
                bp = PREV_BLKP(bp);
                prev_alloc = GET_ALLOC_PREV(HDRP(bp));
                PUT(HDRP(bp), PACK(size, prev_alloc));
                PUT(FTRP(bp), PACK(size, prev_alloc));
        }
        return bp;
}

void *mm_malloc(size_t size)
{
        size_t asize;               /* Adjusted block size */
        size_t extendsize;          /* Amount to extend heap if no fit */
        char *bp;

        /* Ignore spurious requests */
        if (size == 0)
                return NULL;

        /* Adjust block size to include overhead and alignment reqs. */
        asize = DSIZE * ((size + (WSIZE) + (DSIZE-1)) / DSIZE);

        /* Search the free list for a fit */
        bp = find_fit(asize);

        /* No fit found. Get more memory and place the block */
        if (bp == NULL) {
                extendsize = MAX(asize, CHUNKSIZE);
                bp = extend_heap(extendsize/WSIZE);
                if (bp == NULL)
                        return NULL;
        }

        /* Here, we found a fit.  Just place info into it. */
        place(bp, asize);
        return bp;
}

/*
 * 9.8
 */
static void *find_fit(size_t asize)
{
        /* First fit search */
        void *bp;

        for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
                if (!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp)))) {
                        return bp;
                }
        }

        return NULL;            /* No fit */
}

/*
 * place: 分割空闲块
 *
 * 只有当剩余部分的大小等于或者超出最小块的大小时，才进行分割
 */
static void place(void *bp, size_t size)
{
        size_t block_size = GET_SIZE(HDRP(bp));
        size_t reserve_size = block_size - size;
        int    prev_alloc = GET_ALLOC_PREV(HDRP(bp));

        char *next_block;
        size_t next_block_size;
        int next_alloc;

        if (reserve_size < DSIZE) {
                PUT(HDRP(bp), PACK(block_size, prev_alloc | 1));
                next_block = NEXT_BLKP(bp);
                next_block_size = GET_SIZE(HDRP(next_block));
                next_alloc = GET_ALLOC(HDRP(next_block));
                PUT(HDRP(next_block), PACK(next_block_size, next_alloc | 0x2));
        }

        /* 有足够的空间分割空闲块 */
        else if (DSIZE <= reserve_size && reserve_size < block_size) {
                PUT(HDRP(bp), PACK(size, prev_alloc | 1));
                next_block = NEXT_BLKP(bp);
                next_alloc = GET_ALLOC(HDRP(next_block));
                PUT(HDRP(next_block), PACK(reserve_size, next_alloc | 0x2));
                PUT(FTRP(next_block), PACK(reserve_size, next_alloc | 0x2));
        }
}
