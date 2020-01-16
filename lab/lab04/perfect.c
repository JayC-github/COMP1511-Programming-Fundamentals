//Are you perfect
// Jay 2019.03.11

#include<stdio.h>

int main(void){
    int number;
    printf("Enter number: ");
    scanf("%d", & number);
    printf("The factors of %d are:\n", number);
    int x=1,sum=0;
    while(x<=number){
    if(number % x ==0){
       printf("%d\n",x);
       sum= sum+x;
    }
       x++;
    }  
    
    printf("Sum of factors =%d\n",sum); 
    if(sum-number==number){
       printf("%d is a perfect number\n",number);
    }else{
       printf("%d is not a perfect number\n",number);
    }



    return 0;
}
