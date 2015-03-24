# Makefile for csapp chapter 12

# mofaph@gmail.com
# 2013-8-10

CC = gcc
CFLAGS = -Wall
INCLUDES += -I../../common
LIBS += -lpthread

OBJS += csapp.o
OBJS += hello.o
OBJS += echoservert.o
OBJS += echo.o
OBJS += sharing.o
OBJS += badcnt.o
OBJS += goodcnt.o
OBJS += sbuf.o
OBJS += echoservert_pre.o
OBJS += echo_cnt.o
OBJS += echoserverp.o
OBJS += select.o
OBJS += echoservers.o

PROGRAMS += hello
PROGRAMS += echoservert
PROGRAMS += sharing
PROGRAMS += badcnt
PROGRAMS += goodcnt
PROGRAMS += echoservert_pre
PROGRAMS += echoserverp
PROGRAMS += select
PROGRAMS += echoservers

PHONY += all
PHONY += clean

csapp_h = ../../common/csapp.h
csapp_c = ../../common/csapp.c

.PHONY: $(PHONY)

all: $(PROGRAMS)

hello: hello.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hello.o: hello.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

csapp.o: $(csapp_c) $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echoservert: echoservert.o csapp.o echo.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

echoservert.o: echoservert.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echo.o: ../ch11/echo.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

sharing: sharing.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

sharing.o: sharing.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

badcnt: badcnt.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

badcnt.o: badcnt.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

goodcnt: goodcnt.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

goodcnt.o: goodcnt.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echoservert_pre: echoservert_pre.o echo_cnt.o sbuf.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

echoservert_pre.o: echoservert_pre.c $(csapp_h) sbuf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echo_cnt.o: echo_cnt.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

sbuf.o: sbuf.c sbuf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echoserverp: echoserverp.o echo.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

echoserverp.o: echoserverp.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

select: select.o echo.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

select.o: select.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

echoservers: echoservers.o csapp.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

echoservers.o: echoservers.c $(csapp_h)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROGRAMS)
