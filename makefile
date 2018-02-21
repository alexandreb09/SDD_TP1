# compilateur
CC = gcc
#options
CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -lm

#liste des fichiers objets
OBJ = main.o TP1.o ListeChainee.o

#règle de production finale
prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog

#règle de production pour chaque fichier
main.o : main.c ListeChainee.o
	$(CC) -c main.c $(CFLAGS)

TP1.o : TP1.c ListeChainee.o
	$(CC) -c TP1.c $(CFLAGS)

ListeChainee.o : ListeChainee.c
	$(CC) -c ListeChainee.c $(FLAGS)

clean :
	rm -f *.o
