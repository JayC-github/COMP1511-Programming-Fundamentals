// Leap year
// Jay 2019.03.06
// Leap year is a year divides 4 but not 100,or divides 400.

#include <stdio.h>

int main(void){
    
    int leapYear;
    
    printf("Enter year: ");
    scanf("%d", &leapYear);
    
    if ((leapYear % 4 == 0 && leapYear % 100 !=0) 
        || ( leapYear % 400 == 0)) {
        printf("%d is a leap year.\n", leapYear);
    } else {
        printf("%d is not a leap year.\n", leapYear);
    }
    
    return 0;
}
