#include <stdio.h>

struct free_block {
        char *addr;             /* 空闲块的地址 */
        long size;              /* 空闲块的大小 */
};

static struct free_block *start, *end;

static void swap(struct free_block *b1, struct free_block *b2)
{
        struct free_block tmp;

        tmp = *b1;
        *b1 = *b2;
        *b2 = tmp;
}

#define SORT_BY_ADDRESS 001
#define SORT_BY_SIZE    002

static void block_quick_sort(struct free_block *start, struct free_block *end, int type)
{
        if (start >= end)
                return;

        int k = (end - start) >> 1;
        swap(start, start+k);

        struct free_block *last = start;
        int i;
        for (i = 1; start+i < end; i++) {
                struct free_block *block = start+i;
                if ((type == SORT_BY_ADDRESS && block->addr < start->addr) ||
                    (type == SORT_BY_SIZE && block->size < start->size)) {
                        last += 1;
                        swap(last, block);
                }
        }
        swap(start, last);

        block_quick_sort(start, last, type);
        block_quick_sort(last+1, end, type);
}

#define N 15
static struct free_block block[N];

static void init_blocks(void)
{
        int i;
        for (i = 0; i < N; i++) {
                block[i].addr = (char *)0x100 + random() % 100;
                block[i].size = 100 + random() % 100;
        }

        start = &block[0];
        end = &block[N-1];
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
        block_quick_sort(start, end+1, SORT_BY_ADDRESS);
        print_blocks();

        return 0;
}
