//
//  creaMatriz.c
//  
//
//  Created by Ernesto Mata on 01/05/18.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriz.h"

int leeArchivo(int topologia[][100],char *nodos3[], char nodos2[])
{
    int i=0,j,k=0,esNum=0,contPalabras=0,numNodos;
    int costos[100];
    
    char fila[100];
    //char nodos2[300];
    //char *nodos3[100];
    char *nodoFinal[1];
    char *ptrNodoLeido;
    FILE *ptr;
    
    if ((ptr = fopen("nodos.txt","r")) == NULL)
    printf("el archivo no puede abrirse\n");
    
    else
    {
        fscanf(ptr, "%s",fila);
        ptrNodoLeido= strtok(fila,":");
        nodos3[contPalabras]= &nodos2[i];
        
        while(!feof(ptr))
        {
            if (esNum != 0)
            {
                costos[k]= esNum;
                k++;
                ptrNodoLeido= strtok(NULL,":");
            }
            
            if (ptrNodoLeido == NULL)
            {
                fscanf(ptr,"%s",fila);
                ptrNodoLeido= strtok(fila,":");
            }
            
            for(j=0;(char)ptrNodoLeido[j] != '\0';i++)
            {
                nodos2[i]= (char)ptrNodoLeido[j];
                j++;
            }
            
            nodos2[i]= '\0';
            i++;
            contPalabras++;
            
            nodos3[contPalabras]= &nodos2[i];
            
            ptrNodoLeido= strtok(NULL,":");
            esNum= atoi(ptrNodoLeido);
        }
        
        if (esNum != 0)
        {
            costos[k]= esNum;
            k++;
            ptrNodoLeido= strtok(NULL,":");
        }
        
        if (ptrNodoLeido == NULL)
        {
            fscanf(ptr,"%s",fila);
            ptrNodoLeido= strtok(fila,":");
        }
        
        for(j=0;(char)ptrNodoLeido[j] != '\0';i++)
        {
            nodos2[i]= (char)ptrNodoLeido[j];
            j++;
        }
        
        nodos2[i]= '\0';
        i++;
        contPalabras++;
        
        nodos3[contPalabras]= &nodos2[i];
        ptrNodoLeido= strtok(NULL,":");
        esNum= atoi(ptrNodoLeido);
        printf("ptrNodoLeido: %s\n",ptrNodoLeido);
        printf("esNum: %d\n",esNum);
        printf("k: %d\n",k);
        printf("contPalabras: %d\n",contPalabras);
        costos[k]= esNum;
    }
    
    for (i=0; i < contPalabras; i++)
    {
        printf("nodos3[%d]: %s\n",i,nodos3[i]);
    }
    
    for (i=0; i <= k; i++)
    {
        printf("costos[%d]: %d\n",i,costos[i]);
    }
    
    numNodos= sacaNodosReales(contPalabras,nodos3,nodoFinal);
    printf("numNodos: %d\n",numNodos);
    
    creaMatriz(ptr,fila,nodos3,costos,topologia,numNodos);
    
    return numNodos;
}

int sacaNodosReales(int contPalabras,char *nodos3[],char *nodoFinal[])
{
    int nodosIguales,i,j,nNodos;
    char *aux[1];
    
    for (i=0; i < contPalabras; i++)
    {
        aux[0]= nodos3[i];
        //printf("aux: %s\n",aux[0]);
        
        for (j= i+1; j < contPalabras; j++)
        {
            //printf("nodos3[%d] == aux || %s == %s\n",j,nodos3[j],aux[0]);
            
            nodosIguales= strcmp(nodos3[j],aux[0]);
            
            //if (nodos3[j] == aux[0])
            if (nodosIguales == 0)
            {
                nodos3[j]= nodos3[j+1];
                printf("NODO MODIFICADO nodos3[%d]: %s\n",j,nodos3[j]);
                
                for (nodosIguales=j+1; nodosIguales < contPalabras; nodosIguales++)
                nodos3[nodosIguales]= nodos3[nodosIguales+1];
            }
        }
    }
    
    for (i=0; i < contPalabras; i++)
    printf("nodos3[%d]: %s\n",i,nodos3[i]);
    
    nodoFinal[0]= nodos3[i-1];
    
    //printf("contPalabras: %d\n",contPalabras);
    
    for (i=0; (strcmp(nodos3[i],nodoFinal[0])) != 0 ; i++){}
    
    return nNodos= i;
}

void creaMatriz(FILE *ptr,char fila[], char *nodos3[],int costos[],int topologia[][100],int numNodos)
{
    int nodoCorrecto1,nodoCorrecto2,i,j,k=0;
    int indiceCorrecto1,indiceCorrecto2;
    char *ptrNodoLeido,*ptrNodoLeido2;
    
    rewind(ptr);
    
    while (1)
    {
        fscanf(ptr, "%s",fila);
        ptrNodoLeido= strtok(fila,":");
        printf("ptrNodoLeido: %s\n",ptrNodoLeido);
        ptrNodoLeido2= strtok(NULL,":");
        printf("ptrNodoLeido2: %s\n",ptrNodoLeido2);
        
        if (ptrNodoLeido2 == NULL)
        break;
        
        i=0;
        j=0;
        
        nodoCorrecto1= strcmp(ptrNodoLeido,nodos3[i]);
        indiceCorrecto1= i;
        
        while (nodoCorrecto1 != 0)
        {
            indiceCorrecto1++;
            nodoCorrecto1= strcmp(ptrNodoLeido,nodos3[indiceCorrecto1]);
        }
        
        nodoCorrecto2= strcmp(ptrNodoLeido2,nodos3[j]);
        indiceCorrecto2= j;
        
        while (nodoCorrecto2 != 0)
        {
            indiceCorrecto2++;
            nodoCorrecto2= strcmp(ptrNodoLeido2,nodos3[indiceCorrecto2]);
        }
        
        topologia[indiceCorrecto1][indiceCorrecto2]= costos[k];
        topologia[indiceCorrecto2][indiceCorrecto1]= costos[k];
        k++;
    }
    
    //    for (i=0; i < numNodos; i++)
    //    {
    //        for (j=0; j < numNodos; j++)
    //        {
    //            printf("topologia[%d][%d]: %d\n",i,j,topologia[i][j]);
    //        }
    //    }
    
    fclose(ptr);
}
