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
    node *next;
    node *prev;
}listaconjunto;

listaconjunto listaprincipal; // lista principal permite manipular os conjuntos, sendo acessíveis através dos indices

//------------Funções Obrigatórias-------------
node *adicionarconjunto(); // Adicionar novo conjunto de dados
void exclusaoconjunto(node *anterior, int dado); // exclusão de conjunto após elemento selecionado
void editarconjunto(node *anterior, int dado); // edição de elementos do conjunto
void interseccao(); //Intersecção de conuntos
void uniao(); //União de conuntos
void diferenca(); //Diferença de conuntos

//------------Funções Auxiliares-------------
node *insercaoconjunto(listaprincipal *conjunto, node *anterior, int dado); // Adicionar elemento ao conjunto após o elemento selecionado
node *remocao(listaprincipal *conjunto, node *head);// Remocao de elemento em um conjunto
node *buscar(node *head, int dado); //Buscar elemento dentro de um conjunto
void imprimirconjunto(node *head); //Mostrar conjunto
int verificavazio(int top); //Verificar se conjunto esta vazio

//------------Classe Principal-------------
int main(){
    int menu, dado;
    listaconjunto *head, *tail, *conjuntoatual;
    node *headgroup, *tailgroup, *atual, *novo;
    /*
    Ponteiros do tipo node para armazenarem:
    Headgroup - Elemento no topo da lista no conjunto;
    Tailgroup - Ultimo elemento que entrou na lista do conjunto;
    Atual - Manipulação
    */

    printf("Trabalho_NP1\n\n1 - Adicionar Conjunto..\n2 - Excluir Conjunto..\n3 - Alterar conjunto..\n4 ");
    printf("4 - Exibir Intersecção..\n5 - Exibir União..\n6 - Exibir Diferença\n0 - Sair\n");
        scanf("%d", &menu);
        //printf("\033[H\033[J"); //Limpar Tela no Linux
        system("cls");// Limpar tela no Windows

        switch (menu) {
            case 1:
                if(head == NULL){
                    listaprincipal.next = adicionarconjunto();
                    listaprincipal.prev = NULL;
                    listaprincipal.indice = 0;//Indice das lista principal inicia em 0

                    printf("\nPrimeiro conjunto criado!\n");
                }
                else{
                    listaprincipal.head = adicionarconjunto();
                    listaprincipal.indice = listaprincipal.indice  + 1;// incrementa em um o indice da lista principal

                    printf("\nConjunto criado!\n");
                }
                break;
            case 2:
                printf("\nQual conjunto deseja excluir?\n");
                scanf("%d", &dado);

                conjuntoatual = buscar(listaprincipal.head, dado); //Busca através dos índices qual o conjunto a ser excluido

                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado
                    printf("\nConjunto nao encontrado!\n");
                }
                else{ // Libera o espaço alocado para o conjunto selecionado
                    exclusaoconjunto(conjuntoatual);
                }
                break;
            case 3:
                printf("\nQual conjunto deseja editar?\n");
                scanf("%d", &dado);

                conjuntoatual = buscar(listaprincipal.head, dado);//Busca através dos índices qual o conjunto a ser editado

                if(conjuntoatual == NULL){ // Verifica se o conjunto foi encontrado
                    printf("\nConjunto nao encontrado!\n");
                }
                else{ // Permite a edição do conjunto com as opções incluir ou excluir elementos
                    printf("Edição do conjunto %d\n", dado);

                    printf("\n1- Incluir\n2 - Excluir\n");
                    scanf("%d", &dado);
                    switch(dado){
                        case 1:
                            printf("Edição do conjunto %d\n", dado);
                            insercaoconjunto(conjuntoatual)

                    }

                }
        }

}
