#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *push(char *x, char *vet_contrario);
void pop(char *x);

int main(){
    char vet[5], *q, vet_contrario[5];

    scanf("%s", &vet);

    printf("%s \n aa",  push(vet, vet_contrario));
}

char *push(char *x, char *vet_contrario){
  

    //for(i = 0; i < 4; i++){
    //        strcpy(vet_contrario[i], x[3-i]);
    //}
    vet_contrario[0] = x[0];
    vet_contrario[1] = x[1];
    vet_contrario[2] = x[2];
    vet_contrario[3] = x[3];
    return vet_contrario;

}
