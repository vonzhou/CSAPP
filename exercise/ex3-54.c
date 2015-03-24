/*
 * 家庭作业 3.54
 */

int decode2(int x, int y, int z)
{
        int t = (z - y) & 0x7FFF;
        return (x ^ t) * t;
}
