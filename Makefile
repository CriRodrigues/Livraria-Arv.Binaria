SRC=brooks.c main.c menu.c
OBJ=brooks.o main.o menu.o
.c.o:
	cc -c -g $<

all:$(OBJ)
	cc -o livrariab $(OBJ)	

clean:	
	@rm -f *.o > /dev/null
	@rm -f livrariab
