
p:     file format elf32-i386
p
architecture: i386, flags 0x00000112:
EXEC_P, HAS_SYMS, D_PAGED
start address 0x080482f0

Program Header:
    PHDR off    0x00000034 vaddr 0x08048034 paddr 0x08048034 align 2**2
         filesz 0x000000c0 memsz 0x000000c0 flags r-x
  INTERP off    0x000000f4 vaddr 0x080480f4 paddr 0x080480f4 align 2**0
         filesz 0x00000013 memsz 0x00000013 flags r--
    LOAD off    0x00000000 vaddr 0x08048000 paddr 0x08048000 align 2**12
         filesz 0x00000448 memsz 0x00000448 flags r-x
    LOAD off    0x00000448 vaddr 0x08049448 paddr 0x08049448 align 2**12
         filesz 0x000000e8 memsz 0x00000104 flags rw-
 DYNAMIC off    0x00000490 vaddr 0x08049490 paddr 0x08049490 align 2**2
         filesz 0x000000a0 memsz 0x000000a0 flags rw-
    NOTE off    0x00000108 vaddr 0x08048108 paddr 0x08048108 align 2**2
         filesz 0x00000020 memsz 0x00000020 flags r--

Dynamic Section:
  NEEDED      libc.so.6
  INIT        0x8048274
  FINI        0x8048424
  HASH        0x8048128
  STRTAB      0x80481b4
  SYMTAB      0x8048154
  STRSZ       0x69
  SYMENT      0x10
  DEBUG       0x0
  PLTGOT      0x8049474
  PLTRELSZ    0x18
  PLTREL      0x11
  JMPREL      0x804825c
  REL         0x8048254
  RELSZ       0x8
  RELENT      0x8
  VERNEED     0x8048234
  VERNEEDNUM  0x1
  VERSYM      0x8048228

Version References:
  required from libc.so.6:
    0x0d696910 0x00 02 GLIBC_2.0

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .interp       00000013  080480f4  080480f4  000000f4  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.ABI-tag 00000020  08048108  08048108  00000108  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .hash         0000002c  08048128  08048128  00000128  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .dynsym       00000060  08048154  08048154  00000154  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .dynstr       00000073  080481b4  080481b4  000001b4  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .gnu.version  0000000c  08048228  08048228  00000228  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .gnu.version_r 00000020  08048234  08048234  00000234  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .rel.got      00000008  08048254  08048254  00000254  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .rel.plt      00000018  0804825c  0804825c  0000025c  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .init         0000002f  08048274  08048274  00000274  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 10 .plt          00000040  080482a4  080482a4  000002a4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 11 .text         00000134  080482f0  080482f0  000002f0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .fini         0000001a  08048424  08048424  00000424  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .rodata       00000008  08048440  08048440  00000440  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 14 .data         00000018  08049448  08049448  00000448  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 15 .eh_frame     00000004  08049460  08049460  00000460  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 16 .ctors        00000008  08049464  08049464  00000464  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 17 .dtors        00000008  0804946c  0804946c  0000046c  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 18 .got          0000001c  08049474  08049474  00000474  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 19 .dynamic      000000a0  08049490  08049490  00000490  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 20 .bss          0000001c  08049530  08049530  00000530  2**2
                  ALLOC
 21 .stab         00000750  00000000  00000000  00000530  2**2
                  CONTENTS, READONLY, DEBUGGING
 22 .stabstr      0000134f  00000000  00000000  00000c80  2**0
                  CONTENTS, READONLY, DEBUGGING
 23 .comment      0000014f  00000000  00000000  00001fcf  2**0
                  CONTENTS, READONLY
 24 .note         0000008c  0804954c  0804954c  0000211e  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
080480f4 l    d  .interp	00000000              
08048108 l    d  .note.ABI-tag	00000000              
08048128 l    d  .hash	00000000              
08048154 l    d  .dynsym	00000000              
080481b4 l    d  .dynstr	00000000              
08048228 l    d  .gnu.version	00000000              
08048234 l    d  .gnu.version_r	00000000              
08048254 l    d  .rel.got	00000000              
0804825c l    d  .rel.plt	00000000              
08048274 l    d  .init	00000000              
080482a4 l    d  .plt	00000000              
080482f0 l    d  .text	00000000              
08048424 l    d  .fini	00000000              
08048440 l    d  .rodata	00000000              
08049448 l    d  .data	00000000              
08049460 l    d  .eh_frame	00000000              
08049464 l    d  .ctors	00000000              
0804946c l    d  .dtors	00000000              
08049474 l    d  .got	00000000              
08049490 l    d  .dynamic	00000000              
08049530 l    d  .bss	00000000              
00000000 l    d  .stab	00000000              
00000000 l    d  .stabstr	00000000              
00000000 l    d  .comment	00000000              
0804954c l    d  .note	00000000              
00000000 l    d  *ABS*	00000000              
00000000 l    d  *ABS*	00000000              
00000000 l    d  *ABS*	00000000              
00000000 l    df *ABS*	00000000              initfini.c
08048314 l       .text	00000000              gcc2_compiled.
00000000 l    df *ABS*	00000000              init.c
00000000 l    df *ABS*	00000000              crtstuff.c
08048320 l       .text	00000000              gcc2_compiled.
0804944c l     O .data	00000000              p.3
0804946c l     O .dtors	00000000              __DTOR_LIST__
08049450 l     O .data	00000000              completed.4
08048320 l     F .text	00000000              __do_global_dtors_aux
08049460 l     O .eh_frame	00000000              __EH_FRAME_BEGIN__
08048374 l     F .text	00000000              fini_dummy
08049530 l     O .bss	00000018              object.11
08048380 l     F .text	00000000              frame_dummy
080483a8 l     F .text	00000000              init_dummy
08049454 l     O .data	00000000              force_to_data
08049464 l     O .ctors	00000000              __CTOR_LIST__
00000000 l    df *ABS*	00000000              crtstuff.c
080483f0 l       .text	00000000              gcc2_compiled.
080483f0 l     F .text	00000000              __do_global_ctors_aux
08049468 l     O .ctors	00000000              __CTOR_END__
08048418 l     F .text	00000000              init_dummy
08049460 l     O .data	00000000              force_to_data
08049470 l     O .dtors	00000000              __DTOR_END__
08049460 l     O .eh_frame	00000000              __FRAME_END__
00000000 l    df *ABS*	00000000              initfini.c
08048424 l       .text	00000000              gcc2_compiled.
00000000 l    df *ABS*	00000000              main.c
080483b4 l       .text	00000000              gcc2_compiled.
00000000 l    df *ABS*	00000000              swap.c
080483c8 l       .text	00000000              gcc2_compiled.
0804945c g     O .data	00000004              bufp0
08049490 g     O .dynamic	00000000              _DYNAMIC
08048424 g     O *ABS*	00000000              _etext
080482b4  w    F *UND*	00000074              __register_frame_info@@GLIBC_2.0
00000000         *UND*	00000004              _fp_hw
080483c8 g     F .text	00000027              swap
08048274 g     F .init	00000000              _init
080482c4  w    F *UND*	000000a2              __deregister_frame_info@@GLIBC_2.0
080482f0 g       .text	00000000              _start
08049530 g     O *ABS*	00000000              __bss_start
080483b4 g     F .text	00000011              main
080482d4       F *UND*	00000105              __libc_start_main@@GLIBC_2.0
08049448  w      .data	00000000              data_start
08048424 g     F .fini	00000000              _fini
08049454 g     O .data	00000008              buf
08049530 g     O *ABS*	00000000              _edata
08049474 g     O .got	00000000              _GLOBAL_OFFSET_TABLE_
0804954c g     O *ABS*	00000000              _end
08048444 g     O .rodata	00000004              _IO_stdin_used
08049448 g       .data	00000000              __data_start
08049548 g     O .bss	00000004              bufp1
00000000  w      *UND*	00000000              __gmon_start__


Disassembly of section .data:

08049448 <__data_start>:
 8049448:	00 00                	add    %al,(%eax)
	...

0804944c <p.3>:
 804944c:	70 94 04 08                                         p...

08049450 <completed.4>:
 8049450:	00 00 00 00                                         ....

08049454 <buf>:
 8049454:	01 00 00 00 02 00 00 00                             ........

0804945c <bufp0>:
 804945c:	54 94 04 08                                         T...
