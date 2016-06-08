#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_VECTOR 15

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
TpContato *copyVector(TpContato *vet);
void cocktailSort(TpContato *vet);
TpList *createList(int n);
TpList *addContact(TpList *head);// Retornará ponteiro para a HEAD;
TpList *copyList(TpList *head);
void printVector(TpContato *vect);
void printList(TpList *head);
void randomDataList(TpList *neo);
void randomDataVector(TpContato *vect);

//-------------------------Função Principal-------------------
int main(){
    int menu, dado, i;
    TpContato *vect = NULL, *control;
    TpList *head = NULL, *tail, *manipulation;
    /*
    Ponteiro do tipo listaconjunto para armazenarem:
    head - Primeiro conjunto criado. Indica conjunto inicio da fila;
    tail - Ultimo conjunto criado. Indica conjunto no final da fila;
    conjuntoatual - Manipulação;
    */

    do{
        printf("\nTrabalho_NP2\n\n1 - Criar Lista..\n2 - Criar Vetor..\n3 - Algoritmo a ser estudado..\n");
        printf("4 - Método logarítmico..\n0 - Sair\n");
        scanf("%d", &menu);
        __fpurge(stdin);
        getchar();
        printf("\033[H\033[J"); //Limpar Tela no Linux
        //system("cls");// Limpar tela no Windows

        switch (menu) {
            case 1:
                if(head == NULL){
                    printf("How many contacts do you want to create?\n");
                    scanf("%d", &dado);
                    head = createList(dado);
                    printf("List created sucessfully!\n");
                    printList(head);
                }
                else{
                    printf("List already has been created!\n");
                }
                break;
            case 2:
                if(vect == NULL){
                    vect = createVector();
                    printf("Vector created sucessfully!\n\n");
                    printVector(vect);
                }
                else{
                    printf("Vector already has been created!\n");
                }

                break;
            case 3:
                control = copyVector(vect);
                cocktailSort(control);
                printVector(control);
                break;
        }
    }while(menu != 0);
}

TpContato *createVector(){
    int i, id;
    //TpContato *p = calloc(SIZE_VECTOR, sizeof(TpContato));
    TpContato *p = malloc(SIZE_VECTOR * sizeof(TpContato));

    randomDataVector(p);

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
    int id;
    TpList *search;
    TpList *neo = malloc(1*sizeof(TpList));

    if(head == NULL){
        neo->next = NULL;
        neo->prev = NULL;

        randomDataList(neo);

        neo->indice = 0;

        return neo;
    }
    else{
        for(search = head; search->next != NULL; search = search->next);
        search->next = neo;
        neo->prev = search;
        neo->next = NULL;

        randomDataList(neo);

        neo->indice = search->indice + 1;

        return head;
    }
}

void printVector(TpContato *vect){
    int i;

    for(i = 0; i < SIZE_VECTOR; i++){
        printf("--------------------\n");
        printf("Nome: %s\n", vect[i].nome);
        printf("Fone: %s\n", vect[i].fone);
        printf("--------------------\n");
    }
}

void printList(TpList *head){
    TpList *print;

    for(print = head; print != NULL; print = print->next){
        printf("--------------------\n");
        printf("Nome: %s\n", print->contato.nome);
        printf("Fone: %s\n", print->contato.fone);
        printf("--------------------\n");
    }
}

void randomDataList(TpList *neo){
    int id;

    id = (rand () % 999 + 1) + 48;
    snprintf(neo->contato.nome, sizeof neo->contato.nome, "Fulano %03d", id);

    id = (rand () % 99999999 + 1) + 48;
    snprintf(neo->contato.fone, sizeof neo->contato.fone, "%d", id);
}

void randomDataVector(TpContato *vect){
    int i = 0, id, j;
    char code[4], fone[9];

    /*for(i = 0; i < SIZE_VECTOR; i++){
        for(j = 0; j < 3; j++){
            code[j] = (rand () % 10) + 48;
        }

        code[3] = '\0';
        strcpy(vect[i].nome, "Fulano ");
        strcat(vect[i].nome, code);


        for(j = 0; j < 8 ; j++){
            fone[j] = (rand () % 10) + 48;
        }
        fone[8] = '\0';
        strcpy(vect[i].fone, fone);

    }
    */
}

TpContato *copyVector(TpContato *vet){
    int i;
    //TpContato *vetcpy = calloc(SIZE_VECTOR, sizeof(TpContato));
    TpContato *vetcpy = malloc(SIZE_VECTOR * sizeof(TpContato));

    for(i = 0; i < SIZE_VECTOR; i++){
        strcpy(vetcpy[i].nome, vet[i].nome);
        strcpy(vetcpy[i].fone, vet[i].fone);
    }

    return vetcpy;
}

void cocktailSort(TpContato *vet){
    TpContato aux;
    int length, bottom, top, swapped, i;
    length = SIZE_VECTOR;
    bottom = 0;
    top = length - 1;
    swapped = 0;

    while(swapped == 0 && bottom < top){//Se não houver troca de posições ou o ponteiro que
                                    //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1;
        //Ordenação direita para esquerda;
        for(i = bottom; i < top; i = i + 1)
        {
            if(strcmp(vet[i].nome, vet[i + 1].nome) == 1){  //indo pra direita: se o proximo é maior que o atual, troca as posições
                strcpy(aux.nome, vet[i].nome);
                strcpy(aux.fone, vet[i].fone);

                strcpy(vet[i].nome, vet[i + 1].nome);
                strcpy(vet[i].fone, vet[i + 1].fone);

                strcpy(vet[i + 1].nome, aux.nome);
                strcpy(vet[i + 1].fone, aux.fone);
                swapped = 0;
            }
        }

        top = top - 1;// TOP decrementa um pois elemento maior já está à direita.
        //Ordenação esquerda para direita
        for(i = top; i > bottom; i = i - 1){
            if(strcmp(vet[i].nome, vet[i - 1].nome) == -1){
                strcpy(aux.nome, vet[i].nome);
                strcpy(aux.fone, vet[i].fone);

                strcpy(vet[i].nome, vet[i - 1].nome);
                strcpy(vet[i].fone, vet[i - 1].fone);

                strcpy(vet[i - 1].nome, aux.nome);
                strcpy(vet[i - 1].fone, aux.fone);
                swapped = 0;
            }
        }

        bottom = bottom + 1;//BOTTOM incrementa em um pois menor elemento já está à esquerda
    }//fecha while
 }// fim da funçao






