#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 25

void insertionSort(int *a, int n);
void bubbleSort(int *vet, int n);

int main(){

    clock_t c0, c1; // clock_t is defined on <time.h> and <sys/type.h) as int
    int vet[size], i, menu;


    do{
        getchar();
        getchar();
        for(i = 0; i < size; i++){
            vet[i] = rand () % size + 1;
        }
        printf("\033[H\033[J"); //Limpar Tela no Linux
        printf("Vet Original = [");
        for(i = 0; i < size; i++){
            printf("%d, ", vet[i]);
        }
        printf("]\n");
        printf("Ornenar por: \n\n1 - Método insertion Sort\n2 - Método Bubble Sort\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                c0 = clock(); // Inicio tempo de execução
                insertionSort(vet, size);
                c1 = clock();//Fim tempo de execução

                printf("\n\nInsertionSort Vet_Ord = [");
                for(i = 0; i < size; i++){
                    printf("%d, ", vet[i]);
                }
                printf("]\nTempo de execução: %lf\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                break;
            case 2:
                c0 = clock(); // Inicio tempo de execução
                bubbleSort(vet, size);
                c1 = clock();//Fim tempo de execução

                printf("\n\nBubbleSort Vet_Ord = [");
                for(i = 0; i < size; i++){
                    printf("%d, ", vet[i]);
                }
                printf("]\nTempo de execução: %lf\n", (double) (c1 - c0)/CLOCKS_PER_SEC);
                break;

        }
    }while(menu != 0);
}


void bubbleSort(int *vet, int n){
    int troca, aux, i;
    do{
        troca = 0;
        for(i = 1; i < n; i++){
            if(vet[i-1] > vet[i]){
                aux = vet[i];
                vet[i] = vet[i-1];
                vet[i-1] = aux;
                troca = 1;
            }
        }
    }while(troca == 1);
}

void insertionSort(int *a, int n){
    int i, j, chave;

    printf("Ordenando... [");
    for(j = 1; j < n ; j++){
        chave = a[j];
        i = j - 1;

        while(i >=0 && a[i] > chave){
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i + 1] = chave;
    }
    printf("]\n");
}
