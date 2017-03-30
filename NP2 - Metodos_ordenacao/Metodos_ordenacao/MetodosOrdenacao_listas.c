#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct _node{
     int info;
     struct _node *next;
     struct _node *prev;
}node;

//------------------------------Functions
node *addElement(node *head);
node *insertionSort(node *head);
node *bubbleSort(node *head);
void printElements(node *head);

//------------------------------Main
void main(){
    int i, menu;
    clock_t c0, c1; // clock_t is defined on <time.h> and <sys/type.h) as int
    node *head = NULL, *tail, *manipulation;


    do{
        printf("\n1 - Add Element\n2 - Insertion Sort\n3 - Bubble Sort\n0 - Exit\n");
        scanf("%d", &menu);
        printf("\033[H\033[J"); //Limpar Tela no Linux

        switch(menu){
            case 1:
                if(head == NULL){
                    manipulation = addElement(head);
                    head = manipulation;
                    tail = head;

                    printf("\nFirst Element Added!\n");
                    printf("Atual: %p\nNext: %p\nPrev: %p\n", manipulation, manipulation->next, manipulation->prev);
                    printf("Info: %d\n", manipulation->info);
                }
                else{
                    manipulation = addElement(head);
                    tail = manipulation;

                    printf("\nElement Added!\n");
                    printf("Atual: %p\nNext: %p\nPrev: %p\n", manipulation, manipulation->next, manipulation->prev);
                }
                break;
            case 2:
                printElements(head);
                c0 = clock(); // Inicio tempo de execução
                head = bubbleSort(head);
                c1 = clock();//Fim tempo de execução
                printf("\nOrdely List:\n");
                printElements(head);
                printf("\nTempo de execução: %lf\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                getchar();
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }
    }while(menu != 0);
}

// função que retorna ponteio de elemento criado
node *addElement(node *head){
    node *search;
    node *neo = malloc(1*sizeof(node));

    if(head == NULL){
        neo->next = NULL;
        neo->prev = NULL;
        neo->info = rand () % 100 + 1;

        return neo;
    }
    else{
        for(search = head; search->next != NULL; search = search->next);
        search->next = neo;
        neo->prev = search;
        neo->next = NULL;
        neo->info = rand () % 100 + 1;

        return neo;
        }
}


void printElements(node *head){
    node *print;

    printf("C = {");
    for(print = head; print != NULL; print = print->next){
        printf(" %d,", print->info);
    }
    printf("}\n");
}

node *insertionSort(node *head){
    printf("Ordering...");
    node *i, *search;
    int key;

    for(search = head->next; search != NULL ; search = search->next){
        key = search->info;
        i = search->prev;

        while(i != NULL && i->info > key){
            i->next->info = i->info;
            i = i->prev;
        }
        if(i == NULL){
            head->info = key;
        }
        else{
            i->next->info = key;
        }
    }

    return head;
}

node *bubbleSort(node *head){
    int trade, aux;
    node *i, *search;
    do{
        trade = 0;
        for(search = head->next; search != NULL ; search = search->next){
            if(search->prev->info > search->info){
                aux = search->info;
                search->info = search->prev->info;
                search->prev->info = aux;
                trade = 1;
            }
        }
    }while(trade == 1);

    return head;
}

