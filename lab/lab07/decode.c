//Jay z5261536
//2019.04.11
#include<stdio.h>
#include<stdlib.h>

#define ALPHA 26 

int decode(int Character, char *argv[]);

int main(int argc,char *argv[]) {    
    int ch = getchar();
    while (ch != EOF) {
        ch = decode(ch, argv);
        putchar(ch);
        ch = getchar();
    }
    return 0;
}

int decode(int Character, char *argv[]) {
    int newCh = Character;
    if (Character >= 'A' && Character <= 'Z') {   
        newCh = Character - 'A' + 'a';
    }
    int i = 0;
    while (i < ALPHA) {
        if (newCh == argv[1][i]) {
            if (Character >= 'A' && Character <= 'Z') {
                Character = i + 'A';
            } else if (Character >= 'a' && Character <= 'z'){
                Character = i + 'a';
            }    
        
            i = ALPHA;
        }
        i++;
    }
    return Character;   
}    
