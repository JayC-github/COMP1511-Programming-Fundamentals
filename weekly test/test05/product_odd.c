//Jay z5261536
//2019.03.25

#include <stdio.h>

int main (void) {
    int lower,upper;
    printf("Enter lower: ");
    scanf("%d", &lower);
    printf("Enter upper: ");
    scanf("%d", &upper);
    
    
    int x = 1;
    lower = lower + 1;
    while(lower < upper){
        // odd number
        if (lower % 2 == 1) {
            x = x * lower;
        }
        
        lower++;
    }
    
    printf("%d\n", x);
    return 0;
}
