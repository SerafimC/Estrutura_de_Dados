#include <stdio.h>
#include <stdlib.h>

int main(){

    int controle, i = -1;
    int *p = (int *) malloc(5*sizeof(int));;

    if(p == NULL){
        printf("memória insuficiente\n");
    }
    else{
        do{
            i++;
            controle = scanf("%d", &p[i]);
        }while(controle != 0);
    }

    return 0;
}
