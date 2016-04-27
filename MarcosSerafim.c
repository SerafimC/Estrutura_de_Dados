#include <stdlib.h>
#include <stdio.h>

//------------Estruturas-------------
typedef struct _node{
     int info;
     struct _node *next;
     struct _node *prev;
}node;

typedef struct _listaconjunto{
    int indice;
    node *conjunto;
    struct _listaconjunto *ante;
    struct _listaconjunto *prox;
}listaconjunto;

//------------Funções Obrigatórias-------------
listaconjunto *adicionarconjunto(listaconjunto *head); // Função recebe como parametro a head para verificar se a lista não está vazia. Retorna o endereço de memória estrutura que contem do indice do conjunto
listaconjunto *exclusaoconjunto(listaconjunto *conjuntoatual); // exclusão de conjunto após elemento selecionado
void editarconjunto(node *anterior, int dado); // edição de elementos do conjunto
int interseccao(listaconjunto *head); //Intersecção de conjuntos
int uniao(listaconjunto *head); //União de conjuntos
int diferenca(listaconjunto *head); //Diferença de conjuntos

//------------Funções Auxiliares-------------
listaconjunto *buscarconjunto(listaconjunto *head, int dado); //Buscar conjunto dentro de um conjunto
node *buscarelemento(listaconjunto *head, int dado); //Buscar elemento dentro de um conjunto
int insercaoconjunto(listaconjunto *conjuntoatual, int dado); // Adicionar elemento ao conjunto após o elemento selecionado
int remocacoconjunto(listaconjunto *conjunto, int dado);// Remocao de elemento em um conjunto
int imprimirconjunto(listaconjunto *conjuntoatual); //Mostrar conjunto

//------------Classe Principal-------------
int main(){
    int menu, dado, i;
    listaconjunto *head = NULL, *tail, *conjuntoatual;
    /*
    Ponteiro do tipo listaconjunto para armazenarem:
    head - Primeiro conjunto criado. Indica conjunto inicio da fila;
    tail - Ultimo conjunto criado. Indica conjunto no final da fila;
    conjuntoatual - Manipulação;
    */

    do{
        printf("\nTrabalho_NP1\n\n1 - Adicionar Conjunto..\n2 - Excluir Conjunto..\n3 - Alterar conjunto..\n");
        printf("4 - Exibir Intersecção..\n5 - Exibir União..\n6 - Exibir Diferença\n0 - Sair\n");
        scanf("%d", &menu);
        printf("\033[H\033[J"); //Limpar Tela no Linux
        //system("cls");// Limpar tela no Windows

        switch (menu) {
            case 1: // Adicionar Conjunto
                if(head == NULL){ // Não há conjuntos criado;
                    conjuntoatual = adicionarconjunto(head);
                    head = conjuntoatual;
                    tail = head;

                    printf("\nPrimeiro conjunto criado!\n");
                    printf("Indice: %d\n", conjuntoatual->indice);

                }
                else{ // Um ou mais conjuntos criado;
                    conjuntoatual = adicionarconjunto(head);
                    tail = conjuntoatual;

                    printf("\nConjunto criado!\n");
                    printf("Indice: %d\n", conjuntoatual->indice);
                }
                break;

            case 2: // Excluir Conjunto
                if(head == NULL){
                    printf("Não existem conjuntos criados!\n");
                    break;
                }
                printf("\nQual conjunto deseja excluir?\n");

                for(i = 0; i <= tail->indice; i++){ // Loop para imprimir todos os conjuntos existentes
                    conjuntoatual = buscarconjunto(head, i);// Torna o conjuntoatual o de indice i;
                    if(conjuntoatual != NULL){
                      imprimirconjunto(conjuntoatual);//imprime conjuntoatual;
                    }
                }
                scanf("%d", &dado);

                conjuntoatual = buscarconjunto(head, dado); //Busca através dos índices qual o conjunto a ser excluido

                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado, se sim sai do case
                    printf("Conjunto não encontrado!\n");
                    break;
                }
                else{// se não, encontra qual o caso do ponterio e libera o espaço alocado para o conjunto selecionado
                    if(conjuntoatual->prox == NULL && conjuntoatual->ante == NULL){//Exclusão conjunto único
                        conjuntoatual = exclusaoconjunto(conjuntoatual);
                        head = NULL;
                        tail = head;
                        printf("1 - Exclusão feita com sucesso!\n");
                    }
                    else if(conjuntoatual->prox == NULL){//Exclusão ultimo conjunto
                        conjuntoatual = exclusaoconjunto(conjuntoatual);
                        tail = conjuntoatual;
                        printf("Ultimo conjunto excluido com sucesso!\n");
                    }
                    else if(conjuntoatual->ante == NULL){//Exclusão primeiro conjunto;
                         conjuntoatual = exclusaoconjunto(conjuntoatual);
                         head = conjuntoatual;
                         printf("Primeiro conjunto excluido com sucesso!\n");
                    }
                    else{//Exclusão conjunto qualquer
                         conjuntoatual = exclusaoconjunto(conjuntoatual);
                         printf("0 - Exclusão feita com sucesso!\n");
                    }
                }
                dado = 1;
                getchar();getchar();
                printf("\033[H\033[J");
                break;

            case 3:// Alterar conjunto
                for(i = 0; i <= tail->indice; i++){ // Loop para imprimir todos os conjuntos existentes
                    conjuntoatual = buscarconjunto(head, i);// Torna o conjuntoatual o de indice i;
                    if(conjuntoatual != NULL){
                      imprimirconjunto(conjuntoatual);//imprime conjuntoatual;
                    }
                }
                printf("\nQual conjunto deseja editar?\n");
                scanf("%d", &dado);

                conjuntoatual = buscarconjunto(head, dado);//Busca através dos índices qual o conjunto a ser editado
                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado
                    printf("Conjunto não encontrado\n");
                    break;
                }
                else{ // Permite a edição do conjunto com as opções incluir ou excluir elementos
                    do{
                        getchar(); getchar();
                        printf("\033[H\033[J");
                        printf("Edição do conjunto %d\n", conjuntoatual->indice);
                        printf("\n1- Incluir  2 - Excluir 0 - Parar edição\n");
                        scanf("%d", &dado);
                        switch(dado){
                            case 1:
                                imprimirconjunto(conjuntoatual);
                                printf("Novo dado: ");
                                scanf("%d", &dado);

                                dado = insercaoconjunto(conjuntoatual, dado);
                                if(dado == 0){
                                    printf("Elemento já existe no conjunto!\n");
                                }
                                dado = 1;
                                break;
                            case 2:
                                imprimirconjunto(conjuntoatual);
                                printf("Dado a remover: ");
                                scanf("%d", &dado);

                                dado = remocacoconjunto(conjuntoatual, dado);
                                if(dado == 0){
                                    printf("Elemento não existe no conjunto!\n");
                                }
                                dado = 1;
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opcao invalida\n");
                                break;
                        }
                    }while(dado != 0);
                }
                break;
            case 4:
                if(head == NULL){
                    printf("Não existem conjuntos criados!\n");
                    break;
                }
                else if(interseccao(head) == 0){
                    printf("Existe apenas um conjunto criado!\n");
                }
                break;
            case 5:
                if(head == NULL){
                    printf("Não existem conjuntos criados!\n");
                    break;
                }
                else if(uniao(head) == 0){
                    printf("Existe apenas um conjunto criado!\n");
                }
                break;
            case 6:
                if(head == NULL){
                    printf("Não existem conjuntos criados!\n");
                    break;
                }
                else if(diferenca(head) == 0){
                    printf("Existe apenas um conjunto criado!\n");
                }
                break;

        }
    }while(menu != 0);

}

//-------------Funções Implementadas--------

//BUSCAR ELEMENTO - Recebe endereço do conjunto e qual elemento dejesa-se buscar. Retorna o endereço do elemento;
node *buscarelemento(listaconjunto *conjuntoatual, int dado){
    node *busca;

    if(conjuntoatual->conjunto == NULL){
        return NULL;
    }

    for(busca = conjuntoatual->conjunto; busca != NULL; busca = busca->next){
        if(busca->info == dado){
            return busca;
        }
    }
    return NULL;
}

//BUSCAR CONJUNTO - Recebe a Head da classe principal e o indice do conjunto que deseja-se buscar. Retorna o endereço do conjunto;
listaconjunto *buscarconjunto(listaconjunto *head, int dado){
    listaconjunto *busca;

    if(head == NULL){//Evita cair no loop e perder desempenho
        return NULL;
    }

    for(busca = head; busca != NULL; busca = busca->prox){
        if(busca->indice == dado){
            return busca;
        }
    }
    return NULL;
}

//ADICIONAR CONJUNTO - Recebe a Head e busca qual o ultimo conjunto criado e cria conjunto após este.
listaconjunto *adicionarconjunto(listaconjunto *head){
    listaconjunto *busca;
    listaconjunto *neo = malloc(1*sizeof(listaconjunto));

    if(head == NULL){
        neo->prox = NULL;
        neo->ante = NULL;
        neo->conjunto = NULL;
        neo->indice = 0;

        return neo;
    }
    else{
        for(busca = head; busca->prox != NULL; busca = busca->prox);
        busca->prox = neo;
        neo->ante = busca;
        neo->prox = NULL;
        neo->conjunto = NULL;
        neo->indice = busca->indice + 1;

        return neo;
    }
}

//EXCLUSÃO CONJUNTO - Recebe endereço do conjunto que deseja-se excluir.
listaconjunto *exclusaoconjunto(listaconjunto *conjuntoatual){
    listaconjunto *retorno;// Ponteiro auxiliar

    if(conjuntoatual->prox == NULL && conjuntoatual->ante == NULL){//Exclusão conjunto único - Apenas um conjunto existente
        free(conjuntoatual->conjunto);
        free(conjuntoatual);

        return NULL;
    }
    else if(conjuntoatual->prox == NULL){//Exclusão do ultimo conjunto criado.
        retorno = conjuntoatual->ante;
        retorno->prox = NULL;

        free(conjuntoatual->conjunto);
        free(conjuntoatual);

        return retorno;// Retorna ponteiro para que Tail seja atualizado na classe principal
    }
    else if(conjuntoatual->ante == NULL){//Exclusão primeiro conjunto criado;
        retorno = conjuntoatual->prox;
        conjuntoatual->prox->ante = NULL;

        free(conjuntoatual->conjunto);
        free(conjuntoatual);

        return retorno;//Retorna ponteiro do elemento seguinte para que a Head seja atualizada na classe principal
    }
    else{ //Exclusão de conjunto qualquer, não estando em nenhuma das pontas;
        conjuntoatual->ante->prox = conjuntoatual->prox;
        conjuntoatual->prox->ante = conjuntoatual->ante;

        free(conjuntoatual->conjunto);
        free(conjuntoatual);

        return NULL;
    }
}

//IMPRIMIR CONJUNTO - Imprime todos os elementos do conjunto selecionado;
int imprimirconjunto(listaconjunto *conjuntoatual){ //Mostrar conjunto
    node *imprimir;

    printf("C%d = {", conjuntoatual->indice);
    for(imprimir = conjuntoatual->conjunto; imprimir != NULL; imprimir = imprimir->next){
        printf(" %d,", imprimir->info);
    }
    printf("}\n");
    return 1;
}

//INSERÇÃO CONJUNTO - Recebe ponteiro do conjunto e dado a ser inserido
//Retornos: 1 - Inserção feita com sucesso / 0 - Elemento já existe no conjunto
int insercaoconjunto(listaconjunto *conjuntoatual, int dado){

    if(buscarelemento(conjuntoatual, dado) != NULL){
        return 0;
    }

    node *inserir = malloc(1*sizeof(node));
    node *busca;

    inserir->info = dado;

    if(conjuntoatual->conjunto == NULL){// Caso não haja elementenos no conjunto
        conjuntoatual->conjunto = inserir;// Elemento inserir será apondado pela lista principal que contém o indice dos conjuntos
        inserir->next = NULL;
        inserir->prev = NULL;

        return 1;
    }
    else{
        for(busca = conjuntoatual->conjunto; busca->next != NULL; busca = busca->next);

        busca->next = inserir;
        inserir->prev = busca;
        inserir->next = NULL;

        return 1;
    }
}

//REMOÇÃO CONJUNTO - Recebe ponteiro do conjunto e dado a ser removido
//Retornos : 1 - Remoção feita com sucesso / 0 - Elemento não existe no conjunto
int remocacoconjunto(listaconjunto *conjuntoatual, int dado){// Remocao de elemento em um conjunto
    node *remover;

    remover = buscarelemento(conjuntoatual, dado);

    if(remover == NULL){
        return 0;
    }
    else{
        if(remover->prev == NULL && remover->next == NULL){//Remoção de elemento único
            conjuntoatual->conjunto = NULL;

            free(remover);

            return 1;
        }
        else if(remover->next == NULL){//Remoção do ultimo elemento do conjunto
            remover->prev->next = NULL;

            free(remover);

            return 1;
        }
        else if(remover->prev == NULL){ //Remoção primeiro elemento do conjunto
            conjuntoatual->conjunto = remover->next;
            remover->next->prev = NULL;

            free(remover);

            return 1;
        }
        else{
            remover->prev->next = remover->next;
            remover->next->prev = remover->prev;

            free(remover);

            return 1;
        }
    }

}

int interseccao(listaconjunto *head){

   if(head->prox == NULL){
        return 0;
    }
    else{
        listaconjunto *inter = adicionarconjunto(head); //Cria o conjunto de diferença
        node *buscaelemento, *elemento;
        listaconjunto *busca;

        for(buscaelemento = head->conjunto; buscaelemento != NULL; buscaelemento = buscaelemento->next){
            insercaoconjunto(inter, buscaelemento->info);
        }

        for(busca = head->prox; busca->indice != inter->indice; busca = busca->prox){
            if(busca->conjunto != NULL){
                for(buscaelemento = inter->conjunto; buscaelemento != NULL; buscaelemento = buscaelemento->next){
                    elemento = buscarelemento(busca, buscaelemento->info);
                    if(elemento == NULL){
                        remocacoconjunto(inter, buscaelemento->info);
                    }
                    else{
                        insercaoconjunto(inter, buscaelemento->info);
                    }
                }
            }
        }

        printf("Intersecção dos conjuntos:\n");
        imprimirconjunto(inter);
        exclusaoconjunto(inter);

        return 1;
    }
}

int uniao(listaconjunto *head){

    if(head->prox == NULL){
        return 0;
    }
    else{
        listaconjunto *uni = adicionarconjunto(head); //Cria o conjunto de união

        listaconjunto *busca;
        node *buscaelemento;

        for(busca = head; busca != NULL; busca = busca->prox){
            for(buscaelemento = busca->conjunto; buscaelemento != NULL; buscaelemento = buscaelemento->next){
                 if(buscarelemento(uni, buscaelemento->info) == NULL){
                    insercaoconjunto(uni, buscaelemento->info);
                }
            }
        }

        printf("União dos conjuntos:\n");
        imprimirconjunto(uni);
        exclusaoconjunto(uni);

        return 1;
    }
}

int diferenca(listaconjunto *head){

    if(head->prox == NULL){
        return 0;
    }
    else{
        listaconjunto *dif = adicionarconjunto(head); //Cria o conjunto de diferença
        node *buscaelemento, *elemento;
        listaconjunto *busca;

        for(buscaelemento = head->conjunto; buscaelemento != NULL; buscaelemento = buscaelemento->next){
            insercaoconjunto(dif, buscaelemento->info);
        }


        for(busca = head->prox; busca->indice != dif->indice; busca = busca->prox){
            if(busca->conjunto != NULL){
                for(buscaelemento = busca->conjunto; buscaelemento != NULL; buscaelemento = buscaelemento->next){
                    elemento = buscarelemento(dif, buscaelemento->info);
                    if(elemento != NULL){
                        remocacoconjunto(dif, buscaelemento->info);
                    }
                    else{
                        insercaoconjunto(dif, buscaelemento->info);
                    }
                }
            }
        }

        printf("Diferença entre os conjuntos:\n");
        imprimirconjunto(dif);
        exclusaoconjunto(dif);

        return 1;
    }
}
