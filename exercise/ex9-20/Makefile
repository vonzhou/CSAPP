# Makefile for ex9-20

# mofaph@gmail.com
# 2013-6-30

CC = gcc
CFLAGS = -Wall

OBJS += ex9-20.o
OBJS += t9-20.o
OBJS += t-malloc.o

PHONY += clean
PHONY += all
PHONY += TAGS
PHONY += ex9-20
PHONY += tm

.PHONY: $(PHONY)

all: ex9-20 tm

TAGS:
	rm -f TAGS
	find . \( -type d -name .git -prune \) -o \( -type f -name "*.[ch]" \) | xargs etags -

ex9-20: ex9-20.o t9-20.o
	$(CC) $(CFLAGS) $^ -o $@

tm: t-malloc.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) ex9-20 tm TAGS
