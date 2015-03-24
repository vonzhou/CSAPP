# Makefile for ex8-26

# mofaph@gmail.com
# 2013-7-7

CC = gcc
CFLAGS = -Wall

PROGRAM += t
PROGRAM += t-job

OBJS += ex8-26.o
OBJS += random_fork.o
OBJS += job.o

TOBJS += t-job.o

PHONY += all
PHONY += clean
PHONY += TAGS

.PHONY: $(PHONY)

all: $(PROGRAM)

t: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

t-job: t-job.o job.o
	$(CC) $(CFLAGS) $^ -o $@

ex8-26.o: shellex.c
	$(CC) $(CFLAGS) -c $< -o $@

t-job.o: t-job.c job.h
job.o: job.c job.h

TAGS:
	find . -type f -name "*.[ch]" -print | xargs etags -

clean:
	rm -f $(PROGRAM) $(OBJS) $(TOBJS)
