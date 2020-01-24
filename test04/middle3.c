//2019.03.14

#include <stdio.h>

int main(void) {
    int a,b,c;//integer
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    
    if ((a<=b && b<=c) || (c<=b && b<=a)) {
        printf("Middle: %d\n",b);
    } else if ((b<=a && a<=c) || (c<=a && a<=b)) {
        printf("Middle: %d\n",a);
    } else {
        printf("Middle: %d\n",c);   
    }
    return 0;
}


