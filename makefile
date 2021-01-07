CC = gcc
CFLAGS = -Werror -Wall -pedantic -ansi -g
OBJ = print.o Tree.o TreeTest.o
EXEC = tree

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

print.o : print.c print.h
	$(CC) $(CFLAGS) -c print.c

Tree.o : Tree.c Tree.h print.h
	$(CC) $(CFLAGS) -c Tree.c

TreeTest.o : TreeTest.c Tree.h
	$(CC) $(CFLAGS) -c TreeTest.c

clean:
	rm -f $(OBJ) $(EXEC) 
