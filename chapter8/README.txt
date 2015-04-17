












gcc -shared -fPIC -I../include -o csapp.so csapp.c 


gcc fork.c -I../include ./csapp.so -lpthread


fork分别执行1，2，3次的效果分析：
vi fork1.c 
gcc fork1.c -I../include ./csapp.so -lpthread
./a.out 
ppid=3276<Plug>PeepOpenid=6143
ppid=6143<Plug>PeepOpenid=6144






