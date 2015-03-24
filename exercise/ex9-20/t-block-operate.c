#include <stdio.h>
#include <string.h>

struct free_block {
        char *addr;             /* 空闲块的地址 */
        long size;              /* 空闲块的大小 */
};

#define free_block_size(n) ((n) * sizeof(struct free_block))

static struct free_block *start, *end;

static long block_binary_search(long size)
{
        long first = 0;
        long last = end - start;
        long mid = 0;

        while (last > first) {
                mid = (last + first) >> 1;
                struct free_block *ptr = start + mid;
                if (ptr->size < size) {
                        first = mid + 1;
                        mid += 1;
                } else if (ptr->size > size) {
                        last = mid;
                } else /* ptr->size == size */ {
                        return mid;
                }
        }

        return -mid;
}

/*
 * 在这里，空闲块集合中是有序的，按块大小的升序排列（从小到大）
 */
static void insert_free_block(struct free_block *block)
{
        long index = block_binary_search(block->size);
        if (index < 0)
                index = -index;

        end += 1;
        int nblocks = end - start - index;
        size_t size = free_block_size(nblocks);
        memmove(start+index+1, start+index, size);

        *(start+index) = *block;
}

static void remove_free_block(struct free_block *block)
{
        long index = block_binary_search(block->size);
        if (index < 0)
                return;

        int nblocks = end - start - index;
        size_t size = free_block_size(nblocks);
        memmove(start+index, start+index+1, size);
        end -= 1;
}

/*
 * 这个函数用于分割块之后，把余下的空闲块放到合适的位置
 */
static void adjust_free_block(struct free_block *block)
{
        long index = block_binary_search(block->size);
        if (index < 0)
                index = -index;

        struct free_block tmp = *block;
        int nblocks = block - start - index;
        size_t size = free_block_size(nblocks);
        memmove(start+index+1, start+index, size);
        *(start+index) = tmp;
}

#define M 5
#define N 10
static struct free_block block[N];

static void init_blocks(void)
{
        int i;
        for (i = 0; i < M; i++) {
                block[i].addr = (char *)0x100 + i;
                block[i].size = 100 + i;
        }
        for (i = M; i < N; i++) {
                block[i].addr = (char *)0;
                block[i].size = 300 + i;
        }

        start = &block[0];
        end = &block[M];

        struct free_block padding = { NULL, 0 };

        *start = padding;
        *end = padding;
}

void print_blocks(void)
{
        int i;
        for (i = 0; i < N; i++) {
                printf("%02d: %p, %ld\n", i, block[i].addr, block[i].size);
        }
        printf("\n");
}

int main(void)
{
        init_blocks();
        print_blocks();

        char c[10];
        struct free_block b;
        do {
                printf("Your choice: ");
                scanf("%s", c);

                if (c[0] == 'i') {
                        printf("[addr size]: ");
                        scanf("%p %ld", &b.addr, &b.size);
                        insert_free_block(&b);
                        print_blocks();
                } else if (c[0] == 'd') {
                        printf("[addr size]: ");
                        scanf("%p %ld", &b.addr, &b.size);
                        remove_free_block(&b);
                        print_blocks();
                } else if (c[0] == 'p') {
                        print_blocks();
                } else if (c[0] == 'a') {
                        printf("[oldsize newsize]: ");
                        long oldsize, newsize;
                        scanf("%ld %ld", &oldsize, &newsize);
                        int index = block_binary_search(oldsize);
                        block[index].size = newsize;
                        adjust_free_block(&block[index]);
                        print_blocks();
                }

        } while (c[0] != 'q');

        return 0;
}
