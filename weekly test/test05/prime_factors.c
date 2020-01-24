//Jay z5261536
//2019.03.25

#include <stdio.h>

int main(void) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int i = 2;
    int j = 2;
    int x = num;
    int y = num;
    
    while (i < num) {
        if(x % i == 0) {
            x = x/i;    
        } else {
            i++;
       }
    }    
    
    if (x == num) {
        printf("%d is prime\n", num);
    } else {
        printf("The prime factorization of %d is:\n", num);
        while (j <= y) {
            if (y % j == 0){
                printf("%d", j);
                y = y/j;
                if(y != 1){
                    printf("*");
                }
            } else {
                j++;
            }
        }  
        printf("= %d\n", num);    
    }
    return 0;
}
