CC = gcc
CFLAGS = -Wall -pedantic -ansi

OBJ = Main.o MakeMapT.o Traffic.o terminal.o LinkedList.o
EXEC = Assignment

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

Main.o : Main.c Main.h MakeMapT.h LinkedList.h
	$(CC) -c Main.c $(CFLAGS)

MakeMapT.o : MakeMapT.c MakeMapT.h Traffic.h LinkedList.h terminal.h
	$(CC) -c MakeMapT.c $(CFLAGS)

Traffic.o : Traffic.c Traffic.h
	$(CC) -c Traffic.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)

