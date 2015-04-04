all:METODOS
	./executavel -i booleanoENC entrada.txt indice.txt
METODOS:
	gcc -c ledoc.c
	gcc -c booleanoENC.c
	gcc -c booleanoHL.c
	gcc -c HashControle.c
	gcc -c main.c
	gcc -c booleanoRH.c
	gcc ledoc.o booleanoENC.o booleanoHL.o HashControle.o booleanoRH.o main.o -o executavel
	echo "**********Lucas me dá 1 real?**************"
