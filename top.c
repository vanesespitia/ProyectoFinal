#include <stdio.h>
#include <string.h>

int main(void)
{
  FILE *Topologia;
  char aTopo;
  
  printf("me toco la topologia vane :D");
  aTopo=fopen("topologia.txt","r");
  if(aTopo==NULL)
  {
    printf("No existe la topologia");
    exit(0);
  }
  else
  {
    printf("Existe la topologia\n");
  }
  
}
