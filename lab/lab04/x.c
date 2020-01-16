//Jay 2019.03.12
#include<stdio.h>
int main(void){
    int size;
    printf("what's the size: ");
    scanf("%d", &size);
    
    for (int row = 1; row <= size; row++) {
        for(int column = 1; column <= size; column++) {
            if (column == row || column == size + 1 - row) {
                printf("*");
            } else {
                printf("-");
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
    
    int row=1;
    while(row <= size){
    int column=1;
    while(column <= size){
    if (column==row || column==size+1-row){
    printf("*");
    }else{
    printf("-");
    }
    column++;
    }
    printf("\n");
    row++;
    }
    return 0; 
    
*/
