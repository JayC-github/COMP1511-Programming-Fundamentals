//Jay z5261536
//2019.04.10

#include <stdio.h>

#define ALPHABET 26

int main (void) {
    int letter[ALPHABET] = {0};
    int newCh;
    double sum = 0;
    
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            newCh = ch - 'a';
            letter[newCh]++;
            sum++;
        } else if (ch >= 'A' && ch <= 'Z') {
            newCh = ch - 'A';
            letter[newCh]++;
            sum++;
        }    
    }    

    for (int i = 0; i < ALPHABET; i++) {
        printf("'%c' %lf %d\n", 'a' + i, letter[i]/sum, letter[i]);
    }
}














/*
int main(void) {
    int letter[ALPHABET] = {0};
    int newCh = 0;
    double sum = 0;
    int ch;
    
    while ((ch = getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            newCh = ch - 'a';
            letter[newCh]++;
            sum++;
        } else if (ch >= 'A' && ch <= 'Z') {
            newCh = ch - 'A';
            letter[newCh]++;
            sum++;
        } 
    }
    
    int i = 0;
    while (i < ALPHABET) {
        double freq = letter[i]/sum; 
        printf("'%c' %lf %d\n", i +'a', freq, letter[i]);
        i++;
    }
    return 0;
}

*/
