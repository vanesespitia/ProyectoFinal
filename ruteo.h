//
//  ruteo.c
//  
//
//  Created by Ernesto Mata on 01/05/18.
//
//

struct nodoLista
{
    char *nombre;
    int truteo[100];
    struct nodoLista *ptrSiguiente;
    struct nodoLista *conexiones[];
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void generaTablas(char *nombreNodos[],int topologia[][100],int numNodos);
void agregarNodo(ptrNodoLista *ptrS, int pSaltosNodo[],char *nombreNodos[],int numNodo,int numNodos);
void imprimeNodos(ptrNodoLista ptrActual,int numNodos);
