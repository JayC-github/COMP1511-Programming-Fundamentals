//Jay z5261536
//2019.04.14

#include<stdio.h>

#define MAX 4096

int main(void) {
    char string[MAX];
    printf("Enter a string: ");
    fgets(string, MAX, stdin);
    
    int i = 0; // counter for check how many characters in this string.
    while (string[i] != '\n') {
        i++;  
    }
    
    
    int length = i; // i is the number of chara
    int j = i - 1; // The last character 
    
    i = 0; // counter for while loop
    int palindrome = 1;
    while (i < length) {
        if (string[i] != string[j]) {
            palindrome = 0;
        }
         
        i++;
        j--;
    }
    
    if (palindrome == 0) {
        printf("String is not a palindrome\n");
    } else {
        printf("String is a palindrome\n");
    }
    
    return 0;
}
