/*
 * 9.8
 *
 * 为 9.9.12 节中描述的简单分配器实现一个 find_fit 函数
 *
 *     static void *find_fit(size_t asize);
 *
 * 你的解答应该对隐式空闲链表执行首次适配搜索。
 */

static void *find_fit(size_t asize)
{
        char *fit;

        for (fit = NEXT_BLKP(heap_listp);
             GET_SIZE(fit) > 0;
             fit = NEXT_BLKP(fit)) {
                if (GET_ALLOC(fit) && GET_SIZE(fit) >= asize)
                        return (void *)fit;
        }

        return NULL;
}
