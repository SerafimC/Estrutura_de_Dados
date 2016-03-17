#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Funções pop e push
// POP -  Remoção de dados a partir do topo da fila
// PUSH - Inclusão de dados a partir do topo da fila
int push(char *x, int topo);
void pop(char *x);

//Função principal, na qual exister um vetor de char fixo que será invertido com a implementação de PILHAS
int main(){
    char vet[5];
    int top = 4;

    scanf("%s", &vet);

    pop(vet);
    push(vet, top);

    if(top == -1){
        exit(0);
    }
    else{
        printf("%s\nTopo: %d", vet, top);
    }
}

int push(char *x, int topo){
    int i;
    char vet_contrario[5];

    strcpy(vet_contrario, x);

    for(i = (topo); i > -1; i--){
            x[i] = vet_contrario[5-i];
            ;
    }

    return 0;

}
