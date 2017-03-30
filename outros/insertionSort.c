#include <stdlib.h>
#include <stdio.h>

#define size 2000000

void insertionSort(int *a, int n);

int main(){

    int vet[2000000], i;

    for(i = 0; i < size; i++){
        vet[i] = rand() % size + 1;
    }

    printf("Vet = [ ");
    for(i = 0; i < size; i++){
        printf("%d, ", vet[i]);
    }
    printf("]\n");


    insertionSort(vet, size);

    printf("\n\nVet ordenado = [ ");
    for(i = 0; i < size; i++){
        printf("%d, ", vet[i]);
    }
    printf("]\n");

    return;
}

void insertionSort(int *a, int n){
    int i, j, chave;

    for(j = 1; j < n ; j++){
        chave = a[j];
        i = j - 1;

        while(i >=0 && a[i] > chave){
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i + 1] = chave;
    }
}
