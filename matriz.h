//
//  matriz.h
//  
//
//  Created by Ernesto Mata on 01/05/18.
//
//

int leeArchivo(int topologia[][100],char *nodos3[], char nodos2[]);
int sacaNodosReales(int contPalabras,char *nodos3[],char *nodoFinal[]);
void creaMatriz(FILE *ptr,char fila[], char *nodos3[],int costos[],int topologia[][100],int numNodos);
