//Icecream scoops
//Jay 2019.02.26

#include <stdio.h>

int main(void){
    int x, y; // x=scoops,y=How many dollars each scoops
    int z; // How much total cost
    
    printf("How many scoops? ");
    scanf("%d", &x);
    printf("How many dollars does each scoop cost? ");
    scanf("%d", &y);
    z = x * y;
    
    if (z <= 10) {
        printf("You have enough money!\n");
    } else {
        printf("Oh no, you don't have enough money :(\n");    
    }
        
    return 0;
}




