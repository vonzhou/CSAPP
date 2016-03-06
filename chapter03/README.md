# 程序的机器级表示
---
![](.jpg)

> ## 精通细节是理解更深和更基本概念的先决条件 "This is a subject where mastering the details is a prerequisite to understanding the deeper and more fundamental concepts"

### 机器级编程的2种抽象：指令集结构，虚拟地址

### 使用反汇编器，64位系统下指定-m32生成32位的，和书中给出的代码不一样，所以阅读本章的目的是读懂汇编代码

```
Disassembly of section .text:

0000000000000000 <sum>:
   0:	8d 04 37             	lea    (%rdi,%rsi,1),%eax
   3:	01 05 00 00 00 00    	add    %eax,0x0(%rip)        # 9 <sum+0x9>
   9:	c3                   	retq   
```
指定-m32：

```
00000000 <sum>:
   0:	8b 44 24 08          	mov    0x8(%esp),%eax
   4:	03 44 24 04          	add    0x4(%esp),%eax
   8:	01 05 00 00 00 00    	add    %eax,0x0
   e:	c3                   	ret    

```

### IA32整数寄存器
![](registers.jpg)

### 数据传送示例
[exchange.c](exchange.c)









