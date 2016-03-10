#include <stdio.h>
#include <stdlib.h>

int uniao(int *v1,int n1, int *v2, int n2);

int main(){
    int i, n1 = 30, n2 = 2, *vet3;
    int vet1[n1], vet2[n2];

    for(i=0; i<n1; i++){
        vet1[i] = 1;
    }
    for(i=0; i<n2; i++){
        vet2[i] = 2;
    }

    vet3 = (int *) uniao(vet1, n1, vet2, n2);

    printf("vet3 = [");
    for(i = 0; i < (n1+n2); i++){
        printf("%d, ", vet3[i]);
    }
    printf("]\n");

    free(vet3);
}

int uniao(int *v1,int n1, int *v2, int n2){
    int i, *v3 = (int *) malloc((n1+n2)*sizeof(int));

    for(i = 0; i < (n1+n2); i++){
        if(i<n1){
            v3[i] = v1[i];
        }
        else{
            v3[i] = v2[i-n1];
        }
    }

    return v3;
}
