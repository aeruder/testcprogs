CC := gcc

EXT ?=
PROGS := $(addsuffix $(EXT),$(basename $(wildcard *.c)))
PCRE_PROGS := $(addsuffix $(EXT),$(basename $(wildcard pcre_*.c)))
PCRE_LIBS := -L../pcre -lpcre
pcre_test1.c_LIBS := $(PCRE_LIBS)

all: $(PROGS)
clean:
	rm -f $(PROGS)
.PHONY: all clean

.SECONDEXPANSION:

$(PROGS): %$(EXT): %.c
	$(CC) -Wall -O2 $< $($<_CFLAGS) -o $@ $($<_LIBS)

