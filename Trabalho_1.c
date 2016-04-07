#include <stdlib.h>
#include <stdio.h>
#define tam 10

//------------Estruturas-------------
struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;

node* ini();

//-------------Funções----------------
node *init();
node *insercao(node *tail, int dado);
node *remocao(node *head);
int verificavazio(int top);
int verificacheia(int top, int max);

int main () {
    int menu, dado, top = 0;
    node *head, *ultimo, *atual;

    do {
        printf("Trabalho_Filas\n1 - Iniciar fila..\n2 - Insercao..\n3 - Remocao..\n4 - Verificar se esta cheia..\n5 - Verificar se esta vazia..\n0 - Sair\n");
        scanf("%d", &menu);
        system("cls");

        switch (menu) {
            case 1:
                if (top == 0) {
                       head = ini();
                       ultimo = head;
                       printf("Fila iniciada..\n\n");
                   } else {
                       printf("Fila ja iniciada!\n\n");
                   }
                break;
            case 2:
                if (!verificacheia(top, tam)){
                        printf("Digite o valor a ser armazenado: ");
                        scanf("%d", &dado);
                        atual = insercao(ultimo, dado);
                    if (atual != NULL) {
                        ultimo = atual;
                        if (verificavazio(top)) {
                            head = ultimo;
                        }
                        top++;
                    }
                }
                else {
                    printf("FILA CHEIA. Novos dados nao serao gravados\n");
                }
                break;
            case 3:
                if (!verificavazio(top)) {
                    head = remocao(head);
                    top--;
                }
                else {
                    printf("FILA VAZIA\n");
                }
                break;
            case 4:
                if (verificacheia(top, tam))
                    printf("Fila cheia\n");
                else
                    printf("Fila NAO esta cheia\n");
            break;
            case 5:
                if (verificavazio(top))
                    printf("Fila vazia\n");
                else
                    printf("Fila NAO esta vazia\n");
                break;
            case 0:
                printf("Encerrando...");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(menu != 0);

    return 0;
}

node *ini() {
    return NULL;
};

node *insercao(node *ultimo, int value) {

    node *next;
    next = (node *) malloc(1*sizeof(node));
    if (next != NULL) {
        next->num = value;
        next->prox = NULL;
        if (ultimo != NULL)
            ultimo->prox = next;
    }
    return next;
};

node *remocao(node *head) {

    node *new_head;
    new_head = head->prox;
    free(head);
    return new_head;
};

int verificavazio(int size) {

    if (size == 0) {
        return 1;
    }
    return 0;
};
int verificacheia(int top, int max) {
    if (top == max) {
        return 1;
    }
    return 0;
};



