//order3.c
//Jay 03.03.2019

#include <stdio.h>

int main(void){
    int a,b,c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    
    // a smallest
    if (a <= b && a <= c) {
        printf("The integers in order are: %d ",a);
        if(b<=c){
        printf("%d %d", b,c);
        } else {
            printf("%d %d", c,b);
        }
    // b smallest
    } else if (b <= c && b <= a) {
        printf("The integers in order are: %d ",b);
        if (c <= a){
            printf("%d %d", c,a);
        } else {
            printf("%d %d", a,c);
        }
    // c smallest
    } else if (c <= a && c <= b) {
        printf("The integers in order are: %d ",c);
        if(b <= a){
            printf("%d %d", b,a);
        } else {
            printf("%d %d", a,b);
        }
    }  
    
    printf("\n");
    return 0;
}
