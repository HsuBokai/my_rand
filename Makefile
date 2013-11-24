IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)  -Wall -g
#CFLAGS+= `pkg-config --cflags --libs glib-2.0`  -lgcrypt

ODIR=obj
LDIR =./lib

_DEPS = my_rand.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o my_rand.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

target = main

$(target): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(target)
