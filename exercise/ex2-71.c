/*
 * 练习题 2.71
 *
 * 你刚刚开始在一家公司工作，他们要实现一组过程来操作一个数据结构，要将 4 个有
 * 符号字节封装成一个 32 位 unsigned。一个字中的字节从 0（最低有效字节）编号到
 * 3（最高有效字节）。分配给你的任务是：为一个使用补码运算和算数右移的机器编写
 * 一个具有如下原型的函数：
 *
 * Declaration of data type where 4 bytes are packed into an unsigned
 *
 *         typedef unsigned packed_t;
 *
 * Extract byte from word.  Return as signed integer
 *
 *         int xbyte(packed_t word, int bytenum);
 *
 * 也就是说，函数会抽取出指定的字节，再把它符号扩展为一个 32 位 int。你的前任
 * （因为水平不够高而被解雇了）编写了下面的代码：
 *
 * Failed attempt at xbyte
 * int xbyte(packed_t word, int bytenum)
 * {
 *      return (word >> (bytenum << 3)) & 0xFF;
 * }
 *
 * A. 这段代码错在哪里？
 * B. 给出函数的正确实现，只能使用左右移位和一个减法。
 */

/*
 * A. 这段代码不能处理截断的字节是负数的情况。
 */

/*
 * B. 要实现这个函数，我们利用了在算数右移的机器上，无符号是零扩展的，而有符号数
 *    是符号扩展的这个特性。
 */

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
        int shift_left = (3 - bytenum) << 3;

        return (word << shift_left) >> 24;
}
