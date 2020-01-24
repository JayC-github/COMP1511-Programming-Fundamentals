// Jay 2019.03.14

#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i || j == 0 || i == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    
        printf("\n");
    }
       
    return 0;    
}















/*
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    int x = 1;
    while (x <= size) {
        int y = 1;
        while (y <= x) {
            if (y == 1 || y == x || x == size) {
               printf("*");
            } else {
               printf(" ");
            }
            y++;

        }
        printf("\n");
        x++;
    }    
    return 0;
*/
