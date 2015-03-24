        ;; 3.55

        ;; 在完成这道练习的过程中，因为没有考虑到 x * y 会发生隐式类型转换。
        ;; 也就是，y 从 int 类型转换为 long long 类型。这种转换是隐式进行的。
        ;; 因此，我就不能理解为什么要用 x_low * (y>>31) 了。

        ;; 然后，通过在网络上搜索（感谢网络）。我发现了在豆瓣和 stackoverflow 的参考链接

        ;; http://book.douban.com/subject/1230413/annotation?sort=rank&start=20
        ;; http://stackoverflow.com/questions/11680720/implement-64-bit-arithmetic-on-a-32-bit-machine

        ;; dest at %ebp+8, x at %ebp+12, y at %ebp+20
        movl    12(%ebp), %esi  ; x_low -> esi
        movl    20(%ebp), %eax  ; y -> eax
        movl    %eax, %edx      ; y -> edx
        sarl    $31, %edx       ; y>>31 -> edx
        movl    %edx, %ecx      ; y>>31 -> ecx
        imull   %esi, %ecx      ; x_low * (y>>31) -> ecx
        movl    16(%ebp), %ebx  ; x_high -> ebx
        imull   %eax, %ebx      ; y * x_high -> ebx
        addl    %ebx, %ecx      ; y * x_high + (y>>31) * x_low -> ecx
        mull    %esi            ; x_low * y -> edx:eax
        leal    (%ecx, %edx), %edx ; y * x_high + (y>>31)* x_low + edx -> edx
        movl    8(%ebp), %ecx      ; dest -> ecx
        movl    %eax, (%ecx)       ; (x*y)_low -> *dest
        movl    %edx, 4(%ecx)      ; (x*y)_high -> *(dest+4)

        ;; 现在描述实现以上运算的算法：

        ;; 由于两个 64 位数字相乘，它的结果的 64 位表示，对于有符号和无符号都是相同的

        ;; 1. a = x_low * y_low
        ;; 2. b = x_low * y_high
        ;; 3. c = x_high * y_low
        ;; 4. result = a + b + c
