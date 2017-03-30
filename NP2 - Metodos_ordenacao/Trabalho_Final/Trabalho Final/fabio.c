#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main2(int argc, char** argv)
{
   char** nomes; // vetor de strings
   int qtd; // quantidade de strings a serem comparadas
   int i,j; // contadores

   char* temp = (char*) malloc(50*sizeof(char));

   printf("Quantos nomes deseja ordenar ? : ");
   scanf("%i",&qtd);

   nomes = (char**) malloc(qtd*sizeof(char*));
   for(i = 0; i < qtd;++i)
   {
      printf("Entre com nome %i : ",i);
      nomes[i] = (char*) malloc(50*sizeof(char));
      scanf("%s",nomes[i]);
      printf("\n");
   }


  // Rotina de ordenação
   for(i = 1; i < qtd; i++)
      for (j = 0; j < qtd -1 ; j++)
         if(strcmp(nomes[j],nomes[j+1]) > 0)
         {
            strcpy(temp,nomes[j]);
            strcpy(nomes[j],nomes[j+1]);
            strcpy(nomes[j+1],temp);
         }

     free(temp);

   printf("Imprimindo os nomes ordenados\n");
   for(i = 0; i < qtd;++i)
     printf("%s\n",nomes[i]);

  // liberando a memória alocada dinâmicamente
   for(i = 0; i < qtd;++i)
      free(nomes[i]);

     // liberando a memória alocada dinâmicamente
    free(nomes);


   return(0);

}


