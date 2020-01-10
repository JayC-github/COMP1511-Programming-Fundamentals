// order3.c
// Jay 03.03.2019

#include<stdio.h>

int main(void){
    int a,b,c;
    int smallest,middle,largest;
    int smaller1,smaller2,larger1,larger2;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    // compare a and b,find the smaller; compare b and c find the smaller;
    // compare the two smaller one, find the smallest.
    smaller1 = (a<=b)*a + (a>b)*b;
    smaller2 = (c<=b)*c + (c>b)*b;
    smallest= (smaller1<=smaller2)*smaller1 + (smaller1>smaller2)*smaller2;
    
    // same process
    larger1 = (a<=b)*b + (a>b)*a;
    larger2 = (c<=b)*b + (c>b)*c;
    largest = (larger1<=larger2)*larger2 + (larger1>larger2)*larger1;
    
    middle = a + b + c -smallest -largest;
    
    
    printf("The integers in order are: %d %d %d\n", smallest,middle,largest);

    return 0;    
}






