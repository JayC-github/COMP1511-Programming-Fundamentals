//Don't Be So Negative
//2019.02.26

#include <stdio.h>

int main(void){
    int x; //x=number
    
    scanf("%d", &x);
    
    if(x > 0){
       printf("You have entered a positive number.\n");
    } else if (x < 0){
       printf("Don't be so negative!\n");
    } else {
       printf("You have entered zero.\n");
    }
    

    return 0;
}
