// Jay z5261536
// 2019.03.25

#include <stdio.h>

int main (void) {
    int lower,upper;
    printf("Enter lower: ");
    scanf("%d", &lower);
    printf("Enter upper: ");
    scanf("%d", &upper);
    
    
    int x = lower + 1; // The integer between two numbers.
    while (x < upper) {
        printf("%d\n", x);
        x++;
    }

    return 0;
}
