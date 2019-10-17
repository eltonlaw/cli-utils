.PHONY: base_converter
CC = clang
LDFLAGS = -lm
CFLAGS = -g -O0 -Werror -Wall $(LDFLAGS)

base_converter:
	$(CC) $(CFLAGS) -o $@ base_converter.c
