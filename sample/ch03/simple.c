/*
 * p109
 *
 * unix> gcc -S -O1
 */

int simple(int *xp, int y)
{
        int t = *xp + y;
        *xp = t;
        return t;
}
