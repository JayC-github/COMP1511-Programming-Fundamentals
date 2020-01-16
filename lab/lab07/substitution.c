//Jay z5261536
//2019.04.11
#include<stdio.h>
#include<stdlib.h>

#define ALPHA 26 

int Substitu(int Character, int NewCharacter);

int main(int argc,char *argv[]) {    
    int ch = getchar();
    int newCh;
    while (ch != EOF) {
        if ('A' <= ch && ch <= 'Z') {
            ch = ch - 'A' + 'a';
            newCh = argv[1][ch -'a']-'a' + 'A';
            newCh = Substitu(ch, newCh);
        } else {
            newCh = Substitu(ch,argv[1][ch -'a']);
        }
        putchar(newCh);
        ch = getchar();    
    }
    return 0;
}

int Substitu(int Character, int NewCharacter) {
    if ('a' <= Character && Character <= 'z') {
        return NewCharacter;
    } else if ('A' <= Character && Character <= 'Z') {
        return NewCharacter;
    } else {
        return Character;
    }
}
