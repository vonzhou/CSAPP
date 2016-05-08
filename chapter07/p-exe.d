
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


Disassembly of section .init:

08048274 <_init>:
 8048274:	55                   	push   %ebp
 8048275:	89 e5                	mov    %esp,%ebp
 8048277:	53                   	push   %ebx
 8048278:	e8 00 00 00 00       	call   804827d <_init+0x9>
 804827d:	5b                   	pop    %ebx
 804827e:	81 c3 f7 11 00 00    	add    $0x11f7,%ebx
 8048284:	83 bb 18 00 00 00 00 	cmpl   $0x0,0x18(%ebx)
 804828b:	74 05                	je     8048292 <_init+0x1e>
 804828d:	e8 6e 7d fb f7       	call   0 <_init-0x8048274>
 8048292:	89 f6                	mov    %esi,%esi
 8048294:	e8 e7 00 00 00       	call   8048380 <frame_dummy>
 8048299:	e8 52 01 00 00       	call   80483f0 <__do_global_ctors_aux>
 804829e:	8b 5d fc             	mov    0xfffffffc(%ebp),%ebx
 80482a1:	c9                   	leave  
 80482a2:	c3                   	ret    
Disassembly of section .plt:

080482a4 <.plt>:
 80482a4:	ff 35 78 94 04 08    	pushl  0x8049478
 80482aa:	ff 25 7c 94 04 08    	jmp    *0x804947c
 80482b0:	00 00                	add    %al,(%eax)
 80482b2:	00 00                	add    %al,(%eax)
 80482b4:	ff 25 80 94 04 08    	jmp    *0x8049480
 80482ba:	68 00 00 00 00       	push   $0x0
 80482bf:	e9 e0 ff ff ff       	jmp    80482a4 <_init+0x30>
 80482c4:	ff 25 84 94 04 08    	jmp    *0x8049484
 80482ca:	68 08 00 00 00       	push   $0x8
 80482cf:	e9 d0 ff ff ff       	jmp    80482a4 <_init+0x30>
 80482d4:	ff 25 88 94 04 08    	jmp    *0x8049488
 80482da:	68 10 00 00 00       	push   $0x10
 80482df:	e9 c0 ff ff ff       	jmp    80482a4 <_init+0x30>
Disassembly of section .text:

080482f0 <_start>:
 80482f0:	31 ed                	xor    %ebp,%ebp
 80482f2:	5e                   	pop    %esi
 80482f3:	89 e1                	mov    %esp,%ecx
 80482f5:	83 e4 f8             	and    $0xfffffff8,%esp
 80482f8:	50                   	push   %eax
 80482f9:	54                   	push   %esp
 80482fa:	52                   	push   %edx
 80482fb:	68 24 84 04 08       	push   $0x8048424
 8048300:	68 74 82 04 08       	push   $0x8048274
 8048305:	51                   	push   %ecx
 8048306:	56                   	push   %esi
 8048307:	68 b4 83 04 08       	push   $0x80483b4
 804830c:	e8 c3 ff ff ff       	call   80482d4 <_init+0x60>
 8048311:	f4                   	hlt    
 8048312:	90                   	nop    
 8048313:	90                   	nop    

08048314 <gcc2_compiled.>:
 8048314:	90 90 90 90 90 90 90 90 90 90 90 90                 ............

08048320 <__do_global_dtors_aux>:
 8048320:	55                   	push   %ebp
 8048321:	89 e5                	mov    %esp,%ebp
 8048323:	83 ec 08             	sub    $0x8,%esp
 8048326:	83 3d 50 94 04 08 00 	cmpl   $0x0,0x8049450
 804832d:	75 3e                	jne    804836d <__do_global_dtors_aux+0x4d>
 804832f:	eb 12                	jmp    8048343 <__do_global_dtors_aux+0x23>
 8048331:	a1 4c 94 04 08       	mov    0x804944c,%eax
 8048336:	8d 50 04             	lea    0x4(%eax),%edx
 8048339:	89 15 4c 94 04 08    	mov    %edx,0x804944c
 804833f:	8b 00                	mov    (%eax),%eax
 8048341:	ff d0                	call   *%eax
 8048343:	a1 4c 94 04 08       	mov    0x804944c,%eax
 8048348:	83 38 00             	cmpl   $0x0,(%eax)
 804834b:	75 e4                	jne    8048331 <__do_global_dtors_aux+0x11>
 804834d:	b8 c4 82 04 08       	mov    $0x80482c4,%eax
 8048352:	85 c0                	test   %eax,%eax
 8048354:	74 0d                	je     8048363 <__do_global_dtors_aux+0x43>
 8048356:	83 c4 f4             	add    $0xfffffff4,%esp
 8048359:	68 60 94 04 08       	push   $0x8049460
 804835e:	e8 61 ff ff ff       	call   80482c4 <_init+0x50>
 8048363:	c7 05 50 94 04 08 01 	movl   $0x1,0x8049450
 804836a:	00 00 00 
 804836d:	89 ec                	mov    %ebp,%esp
 804836f:	5d                   	pop    %ebp
 8048370:	c3                   	ret    
 8048371:	8d 76 00             	lea    0x0(%esi),%esi

08048374 <fini_dummy>:
 8048374:	55                   	push   %ebp
 8048375:	89 e5                	mov    %esp,%ebp
 8048377:	83 ec 08             	sub    $0x8,%esp
 804837a:	89 ec                	mov    %ebp,%esp
 804837c:	5d                   	pop    %ebp
 804837d:	c3                   	ret    
 804837e:	89 f6                	mov    %esi,%esi

08048380 <frame_dummy>:
 8048380:	55                   	push   %ebp
 8048381:	89 e5                	mov    %esp,%ebp
 8048383:	83 ec 08             	sub    $0x8,%esp
 8048386:	b8 b4 82 04 08       	mov    $0x80482b4,%eax
 804838b:	85 c0                	test   %eax,%eax
 804838d:	74 12                	je     80483a1 <frame_dummy+0x21>
 804838f:	83 c4 f8             	add    $0xfffffff8,%esp
 8048392:	68 30 95 04 08       	push   $0x8049530
 8048397:	68 60 94 04 08       	push   $0x8049460
 804839c:	e8 13 ff ff ff       	call   80482b4 <_init+0x40>
 80483a1:	89 ec                	mov    %ebp,%esp
 80483a3:	5d                   	pop    %ebp
 80483a4:	c3                   	ret    
 80483a5:	8d 76 00             	lea    0x0(%esi),%esi

080483a8 <init_dummy>:
 80483a8:	55                   	push   %ebp
 80483a9:	89 e5                	mov    %esp,%ebp
 80483ab:	83 ec 08             	sub    $0x8,%esp
 80483ae:	89 ec                	mov    %ebp,%esp
 80483b0:	5d                   	pop    %ebp
 80483b1:	c3                   	ret    
 80483b2:	90                   	nop    
 80483b3:	90                   	nop    

080483b4 <main>:
 80483b4:	55                   	push   %ebp
 80483b5:	89 e5                	mov    %esp,%ebp
 80483b7:	83 ec 08             	sub    $0x8,%esp
 80483ba:	e8 09 00 00 00       	call   80483c8 <swap>
 80483bf:	31 c0                	xor    %eax,%eax
 80483c1:	89 ec                	mov    %ebp,%esp
 80483c3:	5d                   	pop    %ebp
 80483c4:	c3                   	ret    
 80483c5:	90                   	nop    
 80483c6:	90                   	nop    
 80483c7:	90                   	nop    

080483c8 <swap>:
 80483c8:	55                   	push   %ebp
 80483c9:	8b 15 5c 94 04 08    	mov    0x804945c,%edx
 80483cf:	a1 58 94 04 08       	mov    0x8049458,%eax
 80483d4:	89 e5                	mov    %esp,%ebp
 80483d6:	c7 05 48 95 04 08 58 	movl   $0x8049458,0x8049548
 80483dd:	94 04 08 
 80483e0:	89 ec                	mov    %ebp,%esp
 80483e2:	8b 0a                	mov    (%edx),%ecx
 80483e4:	89 02                	mov    %eax,(%edx)
 80483e6:	a1 48 95 04 08       	mov    0x8049548,%eax
 80483eb:	89 08                	mov    %ecx,(%eax)
 80483ed:	5d                   	pop    %ebp
 80483ee:	c3                   	ret    
 80483ef:	90                   	nop    

080483f0 <__do_global_ctors_aux>:
 80483f0:	55                   	push   %ebp
 80483f1:	89 e5                	mov    %esp,%ebp
 80483f3:	83 ec 14             	sub    $0x14,%esp
 80483f6:	53                   	push   %ebx
 80483f7:	bb 64 94 04 08       	mov    $0x8049464,%ebx
 80483fc:	83 3d 64 94 04 08 ff 	cmpl   $0xffffffff,0x8049464
 8048403:	74 0c                	je     8048411 <__do_global_ctors_aux+0x21>
 8048405:	8b 03                	mov    (%ebx),%eax
 8048407:	ff d0                	call   *%eax
 8048409:	83 c3 fc             	add    $0xfffffffc,%ebx
 804840c:	83 3b ff             	cmpl   $0xffffffff,(%ebx)
 804840f:	75 f4                	jne    8048405 <__do_global_ctors_aux+0x15>
 8048411:	5b                   	pop    %ebx
 8048412:	89 ec                	mov    %ebp,%esp
 8048414:	5d                   	pop    %ebp
 8048415:	c3                   	ret    
 8048416:	89 f6                	mov    %esi,%esi

08048418 <init_dummy>:
 8048418:	55                   	push   %ebp
 8048419:	89 e5                	mov    %esp,%ebp
 804841b:	83 ec 08             	sub    $0x8,%esp
 804841e:	89 ec                	mov    %ebp,%esp
 8048420:	5d                   	pop    %ebp
 8048421:	c3                   	ret    
 8048422:	90                   	nop    
 8048423:	90                   	nop    
Disassembly of section .fini:

08048424 <_fini>:
 8048424:	55                   	push   %ebp
 8048425:	89 e5                	mov    %esp,%ebp
 8048427:	53                   	push   %ebx
 8048428:	e8 00 00 00 00       	call   804842d <_etext+0x9>
 804842d:	5b                   	pop    %ebx
 804842e:	81 c3 47 10 00 00    	add    $0x1047,%ebx
 8048434:	e8 e7 fe ff ff       	call   8048320 <__do_global_dtors_aux>
 8048439:	8b 5d fc             	mov    0xfffffffc(%ebp),%ebx
 804843c:	c9                   	leave  
 804843d:	c3                   	ret    
