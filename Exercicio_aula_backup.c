#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 5

//------------Estruturas-------------
typedef struct Node{
    int num;
    Node *prox;
} node;

node pos[tam];

//-------------Funções----------------

void iniciarfila();
void insercao(char dado);
int remocao();
void verificacheia();
void verificavazio();

//Função principal, na qual exister um vetor de char fixo que será invertido com a implementação de PILHAS
int main(){
    int i, menu;;

    printf("Pressione ENTER...\n");
    do{
        getchar();
        system("clear");
        printf("EMPILHAR CARACTERES\n1 - Iniciar pilha..\n2 - Digitar caracteres..\n3 - Empilhar..\n4 - Mostrar Pilha..\n0 - sair\n");
        scanf("%d", &menu);


        switch(menu){
            case 1:
                iniciarpilha();
                getchar();
                break;
            case 2:
                scanf("%s", &vet);
                getchar();
                break;
            case 3:
                for(i = (tam-2); i >= 0; i--){
                    empilhar(vet[i]);
                }
                getchar();
                break;
            case 4:
                for(i = 0; i < (tam-1); i++){
                    printf("%c\n",desempilhar());
                }
                getchar();
                break;
            case 0:
                exit(0);
            default:
                return 0;
        }
    }while(menu != 0);

}

void iniciarfila(){
    pos[0].prox = NULL;
    printf("A fila foi iniciada..\n");
}

void insercao(){
    if(pos

    return 0;
}

char desempilhar(){
    char c;
    if(pilhacaracteres.top == -1){
        printf("A pilha está vazia\n");
        return 0;
    }
    else{
        c = pilhacaracteres.pilha[pilhacaracteres.top];
        pilhacaracteres.top -= 1;
    }

    return c;
}
