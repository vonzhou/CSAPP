/*
 * 家庭作业 2.89
 *
 * 分配给你一个任务，编写一个 C 函数来计算 2^x 的浮点表示。你意识到完成这个任务的
 * 最好方法是直接创建结果的 IEEE 单精度表示。当 x 太小时，你的程序将返回0.0。当
 * x 太大时，它会返回 +oo。填写下列代码的空白部分，以计算出正确的结果。假设函数
 * u2f 返回的浮点值与它的无符号参数有相同的位表示。
 *
 * 对于单精度 IEEE 浮点格式，下面列出一些特殊的位模式：
 *
 * [0111 1111 1000 0000 0000 0000 0000 0000] +oo
 * [0000 0000 0000 0000 0000 0000 0000 0000] +0.0
 * [1000 0000 0000 0000 0000 0000 0000 0000] -0.0
 * [?111 1111 1??? ???? ???? ???? ???? ????] NaN
 *
 * [?000 0000 0??? ???? ???? ???? ???? ????] 非规格化数
 * [?*** **** *??? ???? ???? ???? ???? ????] 规格化数（阶码域不是全 0 并且不是全 1）
 */

unsigned f2u(float f)
{
        union { float f; unsigned u; } a;
        a.f = f;
        return a.u;
}

float u2f(unsigned x)
{
        /* 这里假设无符号整数和单精度浮点数的位表示相同 */
        union { unsigned u; float f; } a;
        a.u = x;
        return a.f;
}

float fpwr2(int x)
{
        /* Result exponent and fraction */
        unsigned exp, frac;
        unsigned u;

        if (x < -149) {
                /* Too small.  Return 0.0 */
                exp = 0;
                frac = 0;
        } else if (x < -126) {
                /* Denormalized result */
                exp = 0;
                frac = 1 << (x + 149);
        } else if (x < 129) {
                /* Normalized result */
                exp = x + 127;
                frac = 0;
        } else {
                /* Too big.  Return +oo */
                exp = 0xFF;
                frac = 0;
        }

        /* Pack exp and frac into 32 bits */
        u = exp << 23 | frac;

        /* Return as float */
        return u2f(u);
}
