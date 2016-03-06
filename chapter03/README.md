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

### 数据传送示例-P116
[exchange.c](exchange.c)

```
vonzhou@ubuntu:~/Github/CSAPP/chapter03$ gcc -m32 -O1 -c exchange.c 
vonzhou@ubuntu:~/Github/CSAPP/chapter03$ objdump -d exchange.o 

exchange.o:     file format elf32-i386


Disassembly of section .text:

00000000 <exchange>:
   0:	8b 54 24 04          	mov    0x4(%esp),%edx
   4:	8b 02                	mov    (%edx),%eax
   6:	8b 4c 24 08          	mov    0x8(%esp),%ecx
   a:	89 0a                	mov    %ecx,(%edx)
   c:	c3                   	ret    
```

理解：过程加载后，xp和y分别存储在相对于寄存器esp偏移4，8的地方，这里是esp（**和书中不同**），mov    0x4(%esp),%edx 将xp的值加载到edx中，mov    (%edx),%eax 将xp对应的地址处的值加载到eax中，mov    0x8(%esp),%ecx将y的值加载到ecx中，mov    %ecx,(%edx)将y的值存储到xp对应的存储地址处，ret返回，返回值在eax中，正是*xp之前的值;

1. C语言中的指针其实就是地址，引用指针就是将指针取到寄存器中，然后在存储器访问中使用这个寄存器
2. 函数体中的局部变量x存在寄存器，而非存储器中


### 










