#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------Estruturas--------------------------
typedef struct _contato{
    char nome[40];
    char fone[30];
}TpContato;

typedef struct list{
    int indice;
    TpContato contato;
    struct list *next;
    struct list *prev;
}TpList;

//-------------------------Funções----------------------------
TpContato *createVector();
TpList *createList(int n);
TpList *addContact(TpList *head);// Retornará ponteiro para a HEAD;

//-------------------------Função Principal-------------------
int main(){
    int menu, dado, i, *vect = NULL;
    TpList *head = NULL, *tail, *manipulation;
    /*
    Ponteiro do tipo listaconjunto para armazenarem:
    head - Primeiro conjunto criado. Indica conjunto inicio da fila;
    tail - Ultimo conjunto criado. Indica conjunto no final da fila;
    conjuntoatual - Manipulação;
    */

    do{
        printf("\nTrabalho_NP2\n\n1 - Criar Lista..\n2 - Criar Vetor..\n3 - Algoritmo a ser estudado..\n");
        printf("4 - Método logarítmico..\n5 - Sair\n");
        scanf("%d", &menu);
        printf("\033[H\033[J"); //Limpar Tela no Linux
        //system("cls");// Limpar tela no Windows

        switch (menu) {
            case 1:
                if(vect == NULL){
                    vect = (int*) createVector();
                    printf("Vector created sucessfully!\n");
                }
                else{
                    printf("Vector already has been created!\n");
                }

                break;
            case 2:
            if(head == NULL){
                printf("How many contacts do you want to create?\n");
                scanf("%d", &dado);
                head = createList(dado);
                printf("List created sucessfully!\n");
            }
            else{
                printf("List already has been created!\n");
            }
            break;
        }
    }while(menu != 0);
}

TpContato *createVector(){
    int i, id;
    TpContato vet[40], *p;
    p = vet;

    for(i = 0; i < 40; i++){
        id = rand () % 999 + 1;
        strcpy("Fulano ", vet[i].nome);
        vet[7] = rand()
    }

    return p;
}

TpList *createList(int n){
    int i;
    TpList *head = NULL;

    for(i = 0; i < n; i++){
         head = addContact(head);
    }

    return head;
}

TpList *addContact(TpList *head){
    TpList *search;
    TpList *neo = malloc(1*sizeof(TpList));

    if(head == NULL){
        neo->next = NULL;
        neo->prev = NULL;

        neo->indice = 0;

        return neo;
    }
    else{
        for(search = head; search->next != NULL; search = search->next);
        search->next = neo;
        neo->prev = search;
        neo->next = NULL;

        neo->indice = search->indice + 1;

        return head;
    }
}

