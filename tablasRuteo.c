//
//  tablasRuteo.c
//  
//
//  Created by Ernesto Mata on 01/05/18.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "ruteo.h"

void generaTablas(char *nombreNodos[],int topologia[][100],int numNodos)
{
    int i,j,k;
    int pSaltosNodo[100];
    //char *nombre[5];
   
    FILE *ptrCf,*ptr;
    
    ptrNodoLista ptrInicial= NULL;

    
    if ((ptrCf = fopen("tablas.txt","w")) == NULL)
        printf("El archivo no pudo abrirse");
    
    else
    {
        for (i=0; i < numNodos;i++)
        {
            fprintf(ptrCf,"%s ",nombreNodos[i]);
            
            for (j=0; j < numNodos; j++)
            {
                printf("%d ", topologia[i][j]);
            
                pSaltosNodo[j]= topologia[i][j];
                fprintf(ptrCf,"%d ",pSaltosNodo[j]);
            }
        
            printf("\n");
        
            //printf("i:%d nombreNodos: %s\n",i,nombreNodos[i]);
        
            agregarNodo(&ptrInicial, pSaltosNodo,nombreNodos,i,numNodos);
        
            for (k=0; k < numNodos; k++)
            {
                printf("psaltos[%d]: %d\n ",k, pSaltosNodo[k]);
            }
            
            fprintf(ptrCf,"\n");
        }
    }
    
    
//    if ((ptr = fopen("tablas.txt","r")) == NULL)
//        printf("El archivo no pudo abrirse");
//    
//    else
//    {
//        fscanf(ptr,"%s %d",nombre[0],&k);
//        
//        printf("nombre: %s %d\n",nombre[0],k);
//    }
//    
//    fclose(ptr);
    fclose(ptrCf);
    
    imprimeNodos(ptrInicial,numNodos);


}

void agregarNodo(ptrNodoLista *ptrS, int pSaltosNodo[],char *nombreNodos[],int numNodo,int numNodos)
{
    ptrNodoLista ptrNuevo;
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;
    
    int i;
    
    ptrNuevo= malloc(sizeof(NodoLista));
    
    if (ptrNuevo != NULL)
    {
        printf("numNodo:%d nombreNodos: %s\n",numNodo,nombreNodos[numNodo]);
        
        ptrNuevo->nombre= nombreNodos[numNodo];
        
        for (i=0; i < numNodos; i++)
        {
            ptrNuevo->truteo[i]= pSaltosNodo[i];
        }
        
        ptrNuevo->ptrSiguiente= NULL;
        
        ptrAnterior= NULL;
        ptrActual= *ptrS;
        
        while (ptrActual != NULL && nombreNodos[numNodo] > ptrActual->nombre)
        {
            ptrAnterior= ptrActual;
            ptrActual= ptrActual->ptrSiguiente;
        }
        
        if (ptrAnterior == NULL)
        {
            ptrNuevo->ptrSiguiente= *ptrS;
            *ptrS= ptrNuevo;
        }
        
        else
        {
            ptrAnterior->ptrSiguiente= ptrNuevo;
            ptrNuevo->ptrSiguiente= ptrActual;
        }
    }
    
    else
    {
        printf("No se inserto nodo, no hay memoria\n");
    }
}

void imprimeNodos(ptrNodoLista ptrActual,int numNodos)
{
    int i;
    
    if (ptrActual == NULL)
    {
        printf("No hay nodos\n");
    }
    
    else
    {
        printf("NODOS: \n");
        
        while (ptrActual != NULL)
        {
            printf("%s -> ",ptrActual->nombre);
            
            for (i=0; i < numNodos; i++)
            {
                printf("%d ",ptrActual->truteo[i]);
            }
            
            printf("\n");
            
            ptrActual= ptrActual->ptrSiguiente;
        }
        
        printf("NULL\n");
    }
}










