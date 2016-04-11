#include <stdlib.h>
#include <stdio.h>
#define tam 10

//------------Estruturas-------------
typedef struct _node{
     int info;
     struct _node *next;
     struct _node *prev;
}node;

typedef struct _listaconjunto{
    int indice;
    node *conjunto;
    struct _listaconjunto *prox;
}listaconjunto;

//------------Funções Obrigatórias-------------
listaconjunto *adicionarconjunto(listaconjunto *head); // Função recebe como parametro a head para verificar se a lista não está vazia. Retorna o endereço de memória estrutura que contem do indice do conjunto
void exclusaoconjunto(listaconjunto *conjuntoatual); // exclusão de conjunto após elemento selecionado
void editarconjunto(node *anterior, int dado); // edição de elementos do conjunto
void interseccao(); //Intersecção de conuntos
void uniao(); //União de conuntos
void diferenca(); //Diferença de conuntos

//------------Funções Auxiliares-------------
listaconjunto *buscarconjunto(listaconjunto *head, int dado); //Buscar elemento dentro de um conjunto
void insercaoconjunto(listaconjunto *conjuntoatual, int dado); // Adicionar elemento ao conjunto após o elemento selecionado
void remocacoconjunto(listaconjunto *conjunto, int dado);// Remocao de elemento em um conjunto
void imprimirconjunto(listaconjunto *conjuntoatual); //Mostrar conjunto
int verificavazio(int top); //Verificar se conjunto esta vazio

//------------Classe Principal-------------
int main(){
    int menu, dado;
    listaconjunto *head = NULL, *tail, *conjuntoatual;
    node *headgroup, *tailgroup, *atual, *novo;
    /*
    Ponteiros do tipo node para armazenarem:
    Headgroup - Elemento no topo da lista no conjunto;
    Tailgroup - Ultimo elemento que entrou na lista do conjunto;
    Atual - Manipulação
    */

    do{
        printf("Trabalho_NP1\n\n1 - Adicionar Conjunto..\n2 - Excluir Conjunto..\n3 - Alterar conjunto..\n");
        printf("4 - Exibir Intersecção..\n5 - Exibir União..\n6 - Exibir Diferença\n0 - Sair\n");
            scanf("%d", &menu);
            printf("\033[H\033[J"); //Limpar Tela no Linux
            //system("cls");// Limpar tela no Windows


        switch (menu) {
            case 1:
                if(head == NULL){
                    conjuntoatual = adicionarconjunto(head);
                    head = conjuntoatual;
                    tail = head;

                    printf("\nPrimeiro conjunto criado!\nIndice: %d\n", conjuntoatual->indice);

                }
                else{
                    conjuntoatual = adicionarconjunto(head);
                    tail = conjuntoatual;

                    printf("\nConjunto criado!\n");
                    printf("Indice: %d\n", conjuntoatual->indice);
                }
                break;
            case 2:
                printf("\nQual conjunto deseja excluir?\n");
                scanf("%d", &dado);

                conjuntoatual = buscarconjunto(head, dado); //Busca através dos índices qual o conjunto a ser excluido

                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado
                    break;
                }
                else{// Libera o espaço alocado para o conjunto selecionado
                    exclusaoconjunto(conjuntoatual);
                    printf("Exclusão feita com sucesso!\n");
                }
                break;
            case 3:
                printf("\nQual conjunto deseja editar?\n");
                scanf("%d", &dado);

                conjuntoatual = buscarconjunto(head, dado);//Busca através dos índices qual o conjunto a ser editado
                printf("Indice: %d\n", conjuntoatual->indice);
                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado
                    break;
                }
                else{ // Permite a edição do conjunto com as opções incluir ou excluir elementos
                    printf("Edição do conjunto %d\n", conjuntoatual->indice);

                    printf("\n1- Incluir  2 - Excluir\n");
                    scanf("%d", &dado);
                    switch(dado){
                        case 1:
                            imprimirconjunto(conjuntoatual);
                            printf("Novo dado: ");
                            scanf("%d", &dado);

                            insercaoconjunto(conjuntoatual, dado);
                            break;
                        case 2:
                            imprimirconjunto(conjuntoatual);
                            printf("Dado a remover: ");
                            scanf("%d", &dado);

                            remocacoconjunto(conjuntoatual, dado);
                            break;
                        default:
                            printf("Opcao invalida\n");
                            break;
                    }
                }
                break;
        }
    }while(menu != 0);

}

//-------------Funções Implementadas--------
listaconjunto *buscarconjunto(listaconjunto *head, int dado){ //Buscar elemento dentro de um conjunto
    listaconjunto *busca;

    printf("Head: %d\n", head->indice);

    if(head == NULL){
        printf("Não existem conjuntos criados!\n");
        return NULL;
    }
    for(busca = head; busca->indice != dado; busca = busca->prox){
        printf("Busca: %d\n", busca->indice);
        printf("Dado: %d\n", dado);
        if(busca->indice == dado){
        return busca;
        }
    }
    printf("Conjunto não encontrado!\n");
    return NULL;
}

listaconjunto *adicionarconjunto(listaconjunto *head){ // Função recebe como parametro a head para verificar se a lista não está vazia. Retorna o endereço de memória estrutura que contem do indice do conjunto
    listaconjunto *busca;
    listaconjunto *neo = malloc(1*sizeof(listaconjunto));

    if(head == NULL){
        neo->prox = NULL;
        neo->conjunto = NULL;
        neo->indice = 0;

        return neo;
    }
    else{
        for(busca = head; busca->prox != NULL; busca = busca->prox);
        busca->prox = neo;
        neo->conjunto = NULL;
        neo->indice = busca->indice + 1;

        return neo;
    }

}

void exclusaoconjunto(listaconjunto *conjuntoatual){ // exclusão de conjunto após elemento selecionado
    if(conjuntoatual->conjunto == 0){
        printf("O conjunto já foi excluido ou é inexistente\n");
    }
    else{
    free(conjuntoatual->conjunto);
    }
}

void imprimirconjunto(listaconjunto *conjuntoatual){ //Mostrar conjunto
    node *imprimir;

    printf("C%d = {", conjuntoatual->indice);
    for(imprimir = conjuntoatual->conjunto; imprimir != NULL; imprimir = imprimir->next){
        printf(" %d,", imprimir->info);
    }
    printf("}\n");
}

void insercaoconjunto(listaconjunto *conjuntoatual, int dado){// Adicionar elemento ao conjunto após o elemento selecionado
    node *inserir = malloc(1*sizeof(node));
    node *busca;

    inserir->info = dado;

    if(conjuntoatual->conjunto == NULL){
        conjuntoatual->conjunto = inserir;
        inserir->next = NULL;
        inserir->prev = NULL;
    }
    else{
        for(busca =  conjuntoatual->conjunto; busca->next != NULL; busca = busca->next);

        busca->next = inserir;
        inserir->prev = busca;
    }
}

void remocacoconjunto(listaconjunto *conjunto, int dado){// Remocao de elemento em um conjunto
    node *remover;

    for(remover = conjunto->conjunto; remover->info != dado; remover = remover->next);

    if(remover == NULL){
        printf("Elemento não encontrado!\n");
        exit(0);
    }
    else{
        remover->prev->next = remover->next->prev;
        free(remover);
    }

}


