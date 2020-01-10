//order3.c
//Jay 03.03.2019

#include<stdio.h>

int main(void){
    int a,b,c;

    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);

    
    printf("The integers in order are: %d %d %d\n", 
    a*(a<=b)*(a<=c)+b*(b<=c)*(b<a)+c*(c<b)*(c<a),
    a+b+c-(a*(a<=b)*(a<=c)+b*(b<=c)*(b<a)+c*(c<b)*(c<a))- (a*(a>=b)*(a>=c)+b*(b>=c)*(b>a)+c*(c>b)*(c>a)), a*(a>=b)*(a>=c)+b*(b>=c)*(b>a)+c*(c>b)*(c>a));

    return 0;    
}





