CC = gcc
CFLAGS = -Wall -ansi -pedantic

OBJS = main.o game_init.o game_management.o

all: eat

eat: $(OBJS)
	$(CC) $(CFLAGS) -o eat $(OBJS)

main.o: main.c game_init.h game_management.h
	$(CC) $(CFLAGS) -c main.c

game_init.o: game_init.c game_init.h
	$(CC) $(CFLAGS) -c game_init.c

game_management.o: game_management.c game_management.h game_init.h
	$(CC) $(CFLAGS) -c game_management.c

clean:
	rm -f *.o eat
	
	
