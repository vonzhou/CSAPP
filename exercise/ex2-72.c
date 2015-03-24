/*
 *
 * 给你一个任务，写一个函数，将整数 val 复制到缓冲区 buf 中，但是只有缓冲区
 * buf 中，但是只有当缓冲区中有足够可用的空间时，才执行复制。
 *
 * 你写的代码如下：
 *
 * // Copy integer into buffer if space is available
 * // WARNING: The following code is buggy
 * void copy_int(int val, void *buf, int maxbytes) {
 *     if (maxbytes-sizeof(val) >= 0)
 *         memcpy(buf, (void *)&val, sizeof(val));
 * }
 *
 * 这段代码使用了库函数 memcpy。虽然在这里用这个函数有点刻意，因为我们只是想复
 * 制一个 int，但是说明了一种复制较大数据结构的常见方法。
 *
 * 你仔细地测试了这段代码后发现，哪怕 maxbytes 很小的时候，它也能把值复制到缓
 * 冲区中。
 *
 * A. 解释为什么代码中的条件测试总是成功。提示：sizeof 运算符返回类型为 size_t 的值。
 * B. 你该如何重写这个条件测试，使之工作正确。
 *
 */

/*
 * A. 无论 maxbytes 等于多少，maxbytes-sizeof(int) >= 0 永远为真。因为有符号数和无符号
 *    数进行运算，最终会转换为无符号数。而无符号数的结果永远 >= 0。
 */

/*
 * B. 修改的代码如下
 */
void copy_int(int val, void *buf, int maxbytes)
{
        if (maxbytes > 0 && maxbytes >= sizeof(int))
                memcpy(buf, (void *)&val, sizeof(val));
}
