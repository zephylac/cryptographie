CCOBJ = gcc -c
CCLNK = gcc
CFLAGS = -Wall -ansi -g -D_DEBUG
LIBMATH = -lm


fich_obj_test_hill = test_hill.o hill.o



BIN = test_hill 

test_hill : $(fich_obj_test_hill)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_hill) -o test_hill

test_hill.o : test_hill.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_hill.c -o test_hill.o -I ./ 




OBJ = hill.o

hill.o : hill.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) hill.c -o hill.o -I ./

all : $(BIN) $(OBJ)

clean :
	-rm *.o
	-rm test_hill

