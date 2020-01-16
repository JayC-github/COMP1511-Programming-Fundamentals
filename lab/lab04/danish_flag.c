//Jay 2019.03.13

#include<stdio.h>

int main(void){
    int size;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    
    int row=1;
    while(row<=size*4-2){
    if(row == size*2){
       printf("\n");
       printf("\n");
       }
    int column=1;
    while(column<=size*9-1){
    if(column == size*3){
       printf(" ");
       printf(" ");
       }else{
       printf("#");
    }
       column++;  
    }
       printf("\n");
       row++;
    }
    


    return 0;
}
