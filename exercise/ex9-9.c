/*
 * 9.9
 *
 * 为示例的分配器编写一个 place 函数。
 *
 *     static void place(void *bp, size_t asize);
 *
 * 你的解答应该将请求块放置在空闲块的位置，只有当剩余部分的大小等于或者超出最小块
 * 的大小时，才进行分割。
 */

static void place(void *bp, size_t size)
{
        size_t block_size = GET_SIZE(bp);
        size_t reserve_size = block_size - size;

        if (reserve_size < WSIZE) {
                PUT(HDRP(bp), PACK(block_size, 1));
                PUT(FTRP(bp), PACK(block_size, 1));
        } else if (WSIZE <= reserve_size && reserve_size < block_size) {
                PUT(HDRP(bp), PACK(size, 1));
                PUT(FTRP(bp), PACK(size, 1));

                PUT(HDRP(NEXT_BLKP(bp)), PACK(reserve_size, 0));
                PUT(FTRP(NEXT_BLKP(bp)), PACK(reserve_size, 0));
        }
}
