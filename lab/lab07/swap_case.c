//Jay z5261536
//2019.04.10

#include <stdio.h>

int swap(int cha);

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        int newch = swap(ch);
        putchar(newch);
    }
    return 0;
}

int swap(int cha) {
    int newcha;
    if (cha >= 'a' && cha <= 'z') {
        newcha = cha - 'a' + 'A';
    } else if (cha >= 'A' && cha <= 'Z') {
        newcha = cha - 'A' + 'a';
    } else {
        newcha = cha;
    }
    
    return newcha;
}


/*
int swap_case(int character);

int main(void) {
    int ch = getchar();
    
    while (ch != EOF) {
        int new_ch = swap_case(ch);
        putchar(new_ch);
        ch = getchar();
    }
    return 0;
}

int swap_case(int character) {
    if (character >= 'a' && character <= 'z') {
        int lowToUp = character - 'a';
        return 'A' + lowToUp;
    } else if (character >= 'A' && character <= 'Z') {
        int upToLow = character -'A';
        return 'a' + upToLow;
    } else {
        return character;
    }

}
*/
