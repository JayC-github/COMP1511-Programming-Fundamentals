// Jay z5261536
// 2019.03.14

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int boxes;
    printf("How many boxes: ");
    scanf("%d", &boxes);
    
    int center = 2*boxes;
    int layer;
    
    for (int row = 1; row <= 3+4*(boxes-1); row++){
        for(int column = 1; column <= 3 + 4 *(boxes - 1); column++) {
            int x = abs(center - column);
            int y = abs(center - row);
            
            layer = x >= y ? x : y;
            layer % 2 == 0 ? printf(" ") : printf("*");
        }
       
       
       printf("\n");
    }

   return 0;
}

/*
// method 2
int main(void){
    int boxes;
    printf("How many boxes: ");
    scanf("%d", &boxes);
    int center = 2 * boxes;
    int length = 3 + 4 * (boxes - 1);
    
    for (int i = 1; i <= center; i++) {
        for (int j = 1; j <= length; j++) {    
            // odd line, 11111111-> 10111111101 -> 10101111110101
            int range = length - (i - 1) * 2;
            if (i % 2 == 1) {
                if (j >= center - (range - 1)/2 
                && j <= center + (range - 1)/2) {
                    printf("*");
                } else {
                    j % 2 == 1 ? printf("*"): printf(" ");
                }
            // even line, 100000001 -> 1010000101 -> 101010010101
            } else {    
                if (j >= center - (range - 1)/2 
                && j <= center + (range - 1)/2) {
                    printf(" ");
                } else {
                    j % 2 == 1 ? printf("*"): printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    for (int i = center; i >= 1; i--) {
        for (int j = 1; j <= length; j++) {    
            // odd line, 11111111-> 10111111101 -> 10101111110101
            int range = length - (i - 1) * 2;
            if (i % 2 == 1) {
                if (j >= center - (range - 1)/2 
                && j <= center + (range - 1)/2) {
                    printf("*");
                } else {
                    j % 2 == 1 ? printf("*"): printf(" ");
                }
            // even line, 100000001 -> 1010000101 -> 101010010101
            } else {    
                if (j >= center - (range - 1)/2 
                && j <= center + (range - 1)/2) {
                    printf(" ");
                } else {
                    j % 2 == 1 ? printf("*"): printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
*/

