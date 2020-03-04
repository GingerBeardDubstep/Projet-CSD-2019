SRC = interfaceDepart.c
OBJ = interfaceDepart.o
BIN = interfaceDepart

CFLAGS = `pkg-config --libs --cflags gtk+-2.0`

CC = gcc -c $< $(CFLAGS) -o $@
#LD = gcc -s $^ tableFilm.o parseur.o film.o algoRecom.o tableUtilisateur.o $(CFLAGS) -o $@
LD = gcc -s json.o jWrite.o parseur.o tableFilm.o film.o algoRecom.o tableUtilisateur.o interfaceDepart.o main.o $(CFLAGS) -o main
all : cleanmain json.o jWrite.o parseur.o film.o tableFilm.o algoRecom.o tableUtilisateur.o interfaceDepart.o main clean 


%.o: %.c *.h
	$(CC)

%.o: %.c
	$(CC)

main :
	gcc -c main.c -o main.o
	#gcc json.o jWrite.o parseur.o tableFilm.o film.o algoRecom.o tableUtilisateur.o interfaceDepart.o main.o -o main
	$(LD)

film.o : film.c
	gcc -c film.c -o film.o

tableFilm.o : tableFilm.c  film.o
	gcc -c tableFilm.c -o tableFilm.o -lm

tableUtilisateur.o : tableUtilisateur.c algoRecom.o
	gcc -c tableUtilisateur.c -o tableUtilisateur.o

algoRecom.o : algoRecom.c tableFilm.o
	gcc -c algoRecom.c -o algoRecom.o

parseur.o : parseur.c tableFilm.o
	gcc -c parseur.c -o parseur.o

jWrite.o : jWrite.c
	gcc -c jWrite.c -o jWrite.o

json.o : json.c parseur.o jWrite.o
	gcc -c json.c -o json.o

clean : 
	rm -f *.o
	rm -f *.gch

cleanmain : 
	rm -f main
	#rm -f interfaceDepart
	rm -f *.json

$(BIN): $(OBJ)
	$(LD)
	
