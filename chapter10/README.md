```
➜ CSAPP git:(master) ✗ gcc -shared -fPIC -I../include -o csapp.so common/csapp.c
➜ CSAPP git:(master) ✗ ls -alh csapp.so
-rwxrwxr-x 1 storm storm 30K Oct 9 19:32 csapp.so
➜ CSAPP git:(master) ✗ gcc chapter10/cpstdin.c -I../include ./csapp.so -lpthread
➜ CSAPP git:(master) ✗ ./bin/kafka-server-start.sh ./config/server.properties
➜ CSAPP git:(master) ✗ gcc chapter10/cpstdin.c -I../include ./csapp.so -lpthread -o cpstdin
➜ CSAPP git:(master) ✗ ./cpstdin
hello
hello
^C
```


有待进一步思考：
P612 10.7













