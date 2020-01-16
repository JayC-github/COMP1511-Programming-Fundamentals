//Caesar cipher
//Jay z5261536
//2019.04.10

#include<stdio.h>
#include<stdlib.h>

int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    int ch = getchar();
    while (ch != EOF) {
        
        int new_ch = encrypt(ch,atoi(argv[1]));
        putchar(new_ch);
        
        ch = getchar();
    }  
    return 0;
}

int encrypt(int character, int shift) {
    if (shift < 0) {
        shift = shift%26 + 26;
    }
    if ('a' <= character && character <= 'z') {
        int newCharacter1 = 'a' + ((character - 'a') + shift)%26;
        return newCharacter1;    
    } else if ('A' <= character && character <= 'Z') {
        int newCharacter2 = 'A' + ((character - 'A') + shift)%26;
        return newCharacter2;
    } else {
        return character;
    }
}    

