#include <stdio.h>
#include <stdlib.h>

int main(){

    int controle, i = 0, max = 5;
    int *p = (int *) malloc(max*sizeof(int));;

    if(p == NULL){
        printf("memória insuficiente\n");
    }
    else{
        do{
            controle = scanf("%d", &p[i]);
            i++;
            if(i>=max){
                max = max + 5;
                p = (int *) realloc(p, max*sizeof(int));

                if(p == NULL){
                    printf("memória insuficiente\n");
                }
            }
        }while(controle != 0);
    }

    return 0;
}
