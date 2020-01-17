// Jay z5261536
// 2019.04.14

#include <stdio.h>

#define MAX 4096

int main(void) {
    char line[MAX];
    printf("Enter a string: ");
    fgets(line, MAX, stdin);
    
    int i = 0;
    while (line[i] != '\n') {
        printf("%c\n", line[i]);
        i++;
    }   
     
    return 0;
}
