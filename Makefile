all:METODOS
	./executavel -i booleanoENC entrada.txt indice.txt
METODOS:
	gcc -c ledoc.c
	gcc -c booleanoENC.c
	gcc -c booleanoHL.c
	gcc -c HashControle.c
	gcc -c main.c
	gcc -c booleanoRH.c
	gcc -c vetorial.c
	gcc ledoc.o booleanoENC.o booleanoHL.o HashControle.o booleanoRH.o vetorial.o main.o -o executavel
