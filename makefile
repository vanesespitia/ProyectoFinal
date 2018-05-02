mainProyecto2.out : mainProyecto2.o creaMatriz.o tablasRuteo.o
	gcc -o mainProyecto2.out mainProyecto2.o creaMatriz.o tablasRuteo.o

mainProyecto2.o: mainProyecto2.c matriz.h ruteo.h
	gcc -c mainProyecto2.c

creaMatriz.o: creaMatriz.c matriz.h
	gcc -c creaMatriz.c

tablasRuteo.o: tablasRuteo.c ruteo.h
	gcc -c tablasRuteo.c

clean: 
	rm mainProyecto2.out \ 
	mainProyecto2.o creaMatriz.o