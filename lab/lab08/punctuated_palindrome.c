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
    int length = i; // the number of character(string)     
    
    char Newstring[MAX];
    i = 0;
    int k = 0;
    while (i < length) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            Newstring[k] = string[i] - 'A' + 'a';
            k++;
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            Newstring[k] = string[i];
            k++;
        }
        i++;
    } 
    
    int newLength = k; 
    int j = k-1;
    
    i = 0; // counter for while loop
    int palindrome = 1;
    while (i < newLength) {
        if (Newstring[i] != Newstring[j]) {
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
