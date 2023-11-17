SRC=brooks.c main.c
OBJ=brooks.o main.o
.c.o:
	cc -c $<

all:$(OBJ)
	cc -o livrariab $(OBJ)	

clean:	
	@rm -f *.o > /dev/null
	@rm -f livrariab
