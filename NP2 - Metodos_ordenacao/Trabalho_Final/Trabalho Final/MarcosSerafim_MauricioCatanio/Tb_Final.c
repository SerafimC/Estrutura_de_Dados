#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

//-------------------------Funcoes----------------------------
TpContato *createVector();
TpContato *copyVector(TpContato *vet);

TpList *createList(int n);
TpList *addContact(TpList *head);
TpList *addContactcpy(TpList *head, TpList *headCpy);
TpList *copyList(TpList *head);
TpList *findLastPs(TpList *head);

void printVector(TpContato *vect);
void printList(TpList *head);
void randomDataList(TpList *neo);
void randomDataVector(TpContato *vect);

//-------------------------Funções de Ordenacao---------------
void cocktailSortVector(TpContato *vet);
void cocktailSortList(TpList *head);

void quickSortVector(TpContato *vet, int left, int right);
void quickSortList(TpList *head, TpList *left, TpList *right);

//-------------------------Função Principal-------------------
int main(){
    int menu, dado, i;// Variaveis do MENU PRINCIPAL
    clock_t c0, c1; //Variaveis para calculo de tempo de execução
    TpContato *vect = NULL, *control;// Ponteiros para acesso e manipulação de vetores
    TpList *head = NULL, *tail, *manipulation;// Ponteiros para acesso e manipulação de listas

    do{
        printf("\nTrabalho_NP2\n\n1 - Criar Lista..\n2 - Criar Vetor..\n3 - Algoritmo a ser estudado..\n");
        printf("4 - Método logarítmico..\n0 - Sair\n");
        scanf("%d", &menu);
        getchar();
        printf("\033[H\033[J"); //Limpar Tela no Linux
        //system("cls");// Limpar tela no Windows

        switch (menu) {
            case 1:
                if(head == NULL){// Criar lista
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
            case 2:// Criar Vetor
                if(vect == NULL){
                    vect = createVector();
                    printf("Vector created sucessfully!\n\n");
                    printVector(vect);
                }
                else{
                    printf("Vector already has been created!\n");
                }

                break;
            case 3:// Ordenar vetor e lista CocktailSort
                if(vect != NULL){
                    control = copyVector(vect);
                    printf("Cocktail Sort Vector:\n");
                    c0 = clock(); // Inicio tempo de execução
                    cocktailSortVector(control);
                    c1 = clock();//Fim tempo de execução
                    printVector(control);
                    printf("\nTempo de execução: %lf\n\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                }
                else{
                    printf("Vector has not been created!\n");
                }

                if(head != NULL){
                    manipulation = copyList(head);
                    printf("Cocktail Sort List:\n");
                    c0 = clock(); // Inicio tempo de execução
                    cocktailSortList(manipulation);
                    c1 = clock();//Fim tempo de execução
                    printList(manipulation);
                    printf("\nTempo de execução: %lf\n\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                }
                else{
                    printf("List has not been created!\n");
                }
                break;
            case 4:
                if(vect != NULL){
                    control = copyVector(vect);
                    printf("Quick Sort Vector:\n");
                    c0 = clock(); // Inicio tempo de execução
                    quickSortVector(control, 0, SIZE_VECTOR - 1);
                    c1 = clock();//Fim tempo de execução
                    printVector(control);
                    printf("\nTempo de execução: %lf\n\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                }
                else{
                    printf("Vector has not been created!\n");
                }
                if(head != NULL){
                    manipulation = copyList(head);
                    tail = findLastPs(manipulation);
                    printf("Quick Sort List:\n");
                    c0 = clock(); // Inicio tempo de execução
                    quickSortList(manipulation, manipulation, tail);
                    c1 = clock();//Fim tempo de execução
                    printList(manipulation);
                    printf("\nTempo de execução: %lf\n\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                }
                else{
                    printf("List has not been created!\n");
                }
                break;
                break;

        }
    }while(menu != 0);
    //free(vect);
    //free(control);
    //free(head);
    //free(tail);
    //free(manipulation);
}

//Função aloca memória para um vetor no tamanho igual ao produto de SIZE_VECTOR * TpContato, ou seja, cria um vetor do tipo TpContato.
//Popula este vetor com dados randomicos; Retorna posição de memória da cabeça desde vetor.
TpContato *createVector(){
    int i, id;
    //TpContato *p = calloc(SIZE_VECTOR, sizeof(TpContato));
    TpContato *p = malloc(SIZE_VECTOR * sizeof(TpContato));

    randomDataVector(p);

    return p;
}

//Função recebe como parametro a quantidade de elementos que deverão ser criados, os cria e popula com dados randomicos.
//Retorna a head da lista.
TpList *createList(int n){
    int i;
    TpList *head = NULL;

    for(i = 0; i < n; i++){
         head = addContact(head);
    }

    return head;
}

//Função adiciona elemento à uma lista. É utilziada pela creatList para adicionar os elemntos.
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

//Função para encontrar a ultima posição de uma lista.
//Retorna o endereço do ultimo elemento (tail)
TpList *findLastPs(TpList *head){
    TpList *search;

    for(search = head; search->next != NULL; search = search->next);

    return search;
}

//Função para imprimir um dado vetor na tela.
void printVector(TpContato *vect){
    int i;

    for(i = 0; i < SIZE_VECTOR; i++){
        printf("--------------------\n");
        printf("Nome: %s\n", vect[i].nome);
        printf("Fone: %s\n", vect[i].fone);
        printf("--------------------\n");
    }
}

//Função para imprimir uma dada lista na tela.
void printList(TpList *head){
    TpList *print;

    for(print = head; print != NULL; print = print->next){
        printf("--------------------\n");
        printf("Nome: %s\n", print->contato.nome);
        printf("Fone: %s\n", print->contato.fone);
        printf("--------------------\n");
    }
}

//Função recebe endeço de dado elemento da lista e cria dados randomicos para o mesmo.
void randomDataList(TpList *neo){
    int i = 0, id, j;
    char code[4], fone[9];

    for(i = 0; i < SIZE_VECTOR; i++){
        for(j = 0; j < 3; j++){
            code[j] = (rand () % 10) + 48;
        }

        code[3] = '\0';
        strcpy(neo->contato.nome, "Fulano ");
        strcat(neo->contato.nome, code);


        for(j = 0; j < 8 ; j++){
            fone[j] = (rand () % 10) + 48;
        }
        fone[8] = '\0';
        strcpy(neo->contato.fone, fone);
    }
}

//Função recebe vetor por parametro e o popula com dados aleatórios.
void randomDataVector(TpContato *vect){
    int i = 0, id, j;
    char code[4], fone[9];

    for(i = 0; i < SIZE_VECTOR; i++){
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
}

//Função duplica vetor passado por parametro.
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

//Função recebe por parametro a lista a ser duplicada e retorna o endereço da nova lista duplicada.
TpList *copyList(TpList *head){
    int i;
    TpList *headCpy = NULL, *search;

    for(search = head; search != NULL; search = search->next){
         headCpy = addContactcpy(search, headCpy);
    }

    return headCpy;
}

//Função que adiciona elementos para a lista duplicada e copia o as informaç~oes a lista original
TpList *addContactcpy(TpList *head, TpList *headCpy){
    int id;
    TpList *search;
    TpList *neo = malloc(1*sizeof(TpList));

    if(headCpy == NULL){
        neo->next = NULL;
        neo->prev = NULL;

        strcpy(neo->contato.nome, head->contato.nome);
        strcpy(neo->contato.fone, head->contato.fone);

        neo->indice = 0;

        return neo;
    }
    else{
        for(search = headCpy; search->next != NULL; search = search->next);

        search->next = neo;
        neo->prev = search;
        neo->next = NULL;

        strcpy(neo->contato.nome, head->contato.nome);
        strcpy(neo->contato.fone, head->contato.fone);

        neo->indice = search->indice + 1;

        return headCpy;
    }
}

void cocktailSortVector(TpContato *vet){
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
            if(strcmp(vet[i].nome, vet[i + 1].nome) > 0){  //indo pra direita: se o proximo é maior que o atual, troca as posições
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
            if(strcmp(vet[i].nome, vet[i - 1].nome) < 0){
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

void cocktailSortList(TpList *head){
    int swapped;
    TpContato aux;
    TpList *bottom, *top, *search;

    for(top = head; top->next != NULL; top = top->next);
    bottom = head;
    swapped = 0;

    while(swapped == 0 && bottom->indice < top->indice){//Se não houver troca de posições ou o ponteiro que
                                    //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1;
        //Ordenação esquerda para direita;
       for(search = bottom; search != top; search = search->next){
            if(strcmp(search->contato.nome, search->next->contato.nome) > 0){  //indo pra direita: se o proximo é maior que o atual, troca as posições
                strcpy(aux.nome, search->contato.nome);
                strcpy(aux.fone, search->contato.fone);

                strcpy(search->contato.nome, search->next->contato.nome);
                strcpy(search->contato.fone, search->next->contato.fone);

                strcpy(search->next->contato.nome, aux.nome);
                strcpy(search->next->contato.fone, aux.fone);
                swapped = 0;
            }
        }


        top = top->prev;// TOP decrementa um pois elemento maior já está à direita.
        //Ordenação direita para esquerda
       for(search = top; search != bottom; search = search->prev)       {
            if(strcmp(search->contato.nome, search->prev->contato.nome) < 0){
                strcpy(aux.nome, search->contato.nome);
                strcpy(aux.fone, search->contato.fone);

                strcpy(search->contato.nome, search->prev->contato.nome);
                strcpy(search->contato.fone, search->prev->contato.fone);

                strcpy(search->prev->contato.nome, aux.nome);
                strcpy(search->prev->contato.fone, aux.fone);
                swapped = 0;
            }
        }

        bottom = bottom->next;//BOTTOM incrementa em um pois menor elemento já está à esquerda
    }//fecha while
 }// fim da funçao

void quickSortVector(TpContato *vet, int left, int right){
    int pivo = left, i, j;//4
    TpContato aux;

    for(i = left + 1; i <= right; i++){
        j = i;//1

        if(strcmp(vet[j].nome, vet[pivo].nome) < 0){
            strcpy(aux.nome, vet[j].nome);
            strcpy(aux.fone, vet[j].fone);

            while(j > pivo){
                strcpy(vet[j].nome, vet[j - 1].nome);
                strcpy(vet[j].fone, vet[j - 1].fone);
                j--;
            }
            strcpy(vet[j].nome, aux.nome);
            strcpy(vet[j].fone, aux.fone);
            pivo++;
        }
    }
    if(pivo - 1 > left){
        quickSortVector(vet, left, pivo - 1);
    }
    if(pivo + 1 < right){
        quickSortVector(vet, pivo + 1, right);
    }
 }

void quickSortList(TpList *head, TpList *left, TpList *right){
    TpList *search, *j, *pivo = left;;
    TpContato aux;

    for(search = left->next ; search != right; search = search->next){
        j = search;

        if(strcmp(j->contato.nome, pivo->contato.nome) < 0){
            strcpy(aux.nome, j->contato.nome);
            strcpy(aux.fone, j->contato.fone);

            while(j->indice > pivo->indice){
                strcpy(j->contato.nome, j->prev->contato.nome);
                strcpy(j->contato.fone, j->prev->contato.fone);
                j = j->prev;
            }
            strcpy(j->contato.nome, aux.nome);
            strcpy(j->contato.fone, aux.fone);
            pivo = pivo->next;
        }
    }
    if(search == right){
        j = search;

        if(strcmp(j->contato.nome, pivo->contato.nome) < 0){
            strcpy(aux.nome, j->contato.nome);
            strcpy(aux.fone, j->contato.fone);

            while(j->indice > pivo->indice){
                strcpy(j->contato.nome, j->prev->contato.nome);
                strcpy(j->contato.fone, j->prev->contato.fone);
                j = j->prev;
            }
            strcpy(j->contato.nome, aux.nome);
            strcpy(j->contato.fone, aux.fone);
            pivo = pivo->next;
        }
    }
    if(pivo->prev != NULL){
        if(pivo->prev->indice > left->indice){
            quickSortList(head, left, pivo->prev);
        }
    }
    if(pivo->next != NULL){
        if(pivo->next->indice < right->indice){
            quickSortList(head, pivo->next, right);
        }
    }
}



