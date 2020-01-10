//3or5
//Jay 2018.03.07

#include <stdio.h>

int main(void){
    int number;
    int i = 1;
    printf("Enter number: ");
    scanf("%d", &number);
    while(i < number){
        if(i % 3 == 0 || i % 5 == 0){
            printf("%d\n", i);
        }
        
        i++;
    }
    
    return 0;
}
