#include <stdlib.h>
#include <stdio.h>


//------------Estruturas-------------
typedef struct _circularlist{
    int indice;
    struct _circularlist *prev;
    struct _circularlist *next;
}circularlist;

//------------Funções----------------
circularlist *addElement(circularlist *head);
circularlist *removeElement(circularlist *head);
int *countElements(circularlist *head);

int main(){
    int menu, data;
    circularlist *head, *tail, *manipulation;

    do{
        printf("\nCircular_Lists_Exercise\n\n1 - Element Adition..\n2 - Elemente Exclusion..\n3 - Number of Elements..\n0 - Exit..\n");
        scanf("%d", &menu);
        printf("\033[H\033[J"); //Clean Linux Terminal

        switch(menu){
            case 1: // Adicionar Conjunto
                if(head == NULL){ // Não há conjuntos criado;
                    manipulation = addElement(head);
                    head = manipulation;
                    tail = head;

                    printf("\nFirst element added!\n");
                    printf("Indice: %d\n", manipulation->indice);
                }
                else{ // Um ou mais conjuntos criado;
                    manipulation = addElement(head);
                    tail = manipulation;

                    printf("\nElement added!\n");
                    printf("Indice: %d\n", manipulation->indice);
                }
                break;
                break;
            case 2:
                break;
            case 3:
                data = countElements(head);
                printf("Number of elements created: %d\n", data);
                break;
        }


    }while(menu != 0);
}

circularlist *addElement(circularlist *head){
    circularlist *search;
    circularlist *neo = malloc(1*sizeof(circularlist));

    if(head == NULL){
        neo->next = NULL;
        neo->prev = NULL;
        neo->indice = 0;

        return neo;
    }
    else{
        for(search = head; search->next != NULL; search = search->next);
        head->prev = neo;

        search->next = neo;

        neo->prev = search;
        neo->next = NULL;
        neo->indice = search->indice + 1;

        return neo;
    }
}

int *countElements(circularlist *head){
    circularlist *search;
    int elementcounter = 0;

    if(head->next != NULL){
        elementcounter++;
        for(search = head->next; search->indice != 0; search = search->next){
            elementcounter++;
        }
    }

    return elementcounter;
}
