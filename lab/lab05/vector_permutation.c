//Jay z5261536
//2019.03.25

#include<stdio.h>

int main (void) {
    int length;
    printf("Enter vector length: ");
    scanf("%d", & length);
    
    int i = 0;
    int vector[length];
    printf("Enter vector: ");
    while (i < length) {
        scanf("%d", & vector[i]);
        i++;
    }
    
    int j = 0;
    int perm[length];
    printf("Enter permutation: ");
    while (j < length) {
        scanf("%d", & perm[j] );
        if (perm[j] < 0 || perm[j] >= length ) {
            printf("Invalid permutation\n");
            return 0;
        }
        
        j++;
    }
//Rearrange
    int k = 0;
    while (k < length) {
        printf("%d ", vector[perm[k]]);
        k++;
    }
    printf("\n");
    return 0;
}
