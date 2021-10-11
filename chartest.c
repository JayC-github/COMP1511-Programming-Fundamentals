#include <stdio.h>

int main(void) {
    char *str = "abc123\n";

    for (char *c = str; c != '\0'; c++) {
        putchar(*c);
    }

    return 0;
}

/*#include<stdio.h>

int main(void) {
    int n[4] = { 42, 23, 11, 7 };
    int *p;
    
    p = &n[0];
    printf("%d\n", *p);
    
    n[0]++;
    printf("%d\n", *p);
    p++;
    printf("%p\n", p);
    printf("%d\n", *p);
    
    p--;
    printf("%p\n", p);
    printf("%d\n", *p);
    return 0;
}

I have no idea

*/
