//Jay z5261536
// 2019.04.04

#include <stdio.h>

int isvowel(int cha);

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (!isvowel(ch)) {
            putchar(ch);
        }
    }    

    return 0;
}

int isvowel(int cha) {
    if (cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u') {
        return 1;
    } else {
        return 0;
    }
}

/*
int is_vowel(int character);

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        if (is_vowel(ch) == 0) {
            putchar(ch); // printf("%c", ch); also works
        }
        ch = getchar();
    }

    return 0;
}

int is_vowel(int character){ // 1 means lower case vowel, 0 means not
    if (character != 'a' && character != 'e' && character != 'i' && character != 'o' && character != 'u') {
        return 0;
    } else {
        return 1;
    }
}

*/
