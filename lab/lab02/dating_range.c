// Dating range 
// Jay 2019.02.27

#include <stdio.h>

int main(void) {
    int age, x, y; // x is lower limit age, y is upper limit age
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    x = age/2 + 7, y = (age-6) * 2;
    
    if (age > 12) {
        printf("Your dating range is %d to %d years old.\n", x, y);
    } else {
        printf("You are too young to be dating.\n");
    } 
    
    return 0;
}

