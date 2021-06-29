HEADES = tokenizer.h

all: uimain

uimain: uimain.o tokenizer.o 
	gcc uimain.o tokenizer.o -o uimain
uimain.o: uimain.c $(HEADER)
	gcc -c uimain.c -o uimain.o

tokeinzer.o: tokenizer.c
	gcc -c tokeinzer.c -o tokenizer.o
clean:
	-rm *.o
	-rm *~
	-rm *.c#
	-rm uimain
