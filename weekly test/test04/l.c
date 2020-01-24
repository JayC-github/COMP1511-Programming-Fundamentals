//Jay 2019.03.14

#include<stdio.h>

int main(void){
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    
    int x = 1;
    while(x < size) {
        printf("*\n");
        x++;  
    } 
    
    int y = 1;
    while(y <= size) {
        printf("*");
        y++;
    }
    printf("\n");
    return 0;
}
