/*
 * 3.67
 *
 * mofaph@gmail.com
 */

union ele {
        struct {
                int *p;
                int x;
        } e1;

        struct {
                int y;
                union ele *next;
        } e2;
};

/*
 * A. e1.p: 0, e1.x: 4, e2.y: 0, e2.next = 4
 * B. 8 个字节
 * C. 填写的缺失代码如下
 */
void proc(union ele *up)
{
        up->next->x = *(up->next->p) - up->y;
}
