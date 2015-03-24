/*
 * 3.57
 *
 * 参考链接：
 *
 * http://book.douban.com/annotation/20427266/
 */

/*
 * 在条件传送中，既然不能对数值为 0 的地址取值。通过思维转换，那么就取数值 0 的地
 * 址和数值非 0 的地址。然后再通过这个指针取值
 */
int cread_alt(int *xp)
{
        int t = 0;
        return *(xp ? xp : &t);
}
