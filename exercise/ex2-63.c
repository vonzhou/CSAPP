/*
 * 练习题 2.63
 *
 * 将下面的 C 函数代码补充完整。函数 srl 用算术右移（由值 xsra 给出）来完成逻辑右
 * 移，后面的其他操作不包括右移或者除法。函数 sra 用逻辑右移（由值 xsrl 给出）来
 * 完成算术右移，后面的其他操作不包括右移或者除法。可以通过计算8*sizeof(int) 来确
 * 定数据类型 int 中的位数 w。位移量 k 的取值范围位 0~w-1。
 */

static int w = sizeof(int) << 3;

int sra(int x, int k)
{
        /* Perform shift logically */
        int xsrl = (unsigned) x >> k;

        int sign = ((1 << (w - 1 - k)) & xsrl) << 1;
        int t = ~((1 << (w - k)) - 1); /* t=[11...1100...00], w-1...w-k 位全 1 */

        /*
         * sign = 0, n = 0
         * sign = [0...010...0], n = t
         */
        int n = t + (sign ^ (1 << (w - k)));

        return n + xsrl;
}

unsigned srl(unsigned x, int k)
{
        /* Perform shift arithmetically */
        unsigned xsra = (int) x >> k;
        return xsra & ((1 << (w-k)) - 1);
}
