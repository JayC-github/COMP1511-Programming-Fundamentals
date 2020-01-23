#include <stdio.h>
#include <stdlib.h>

void match(char pokemon[], char text[]) { // return 0 means not matching
                                        // return 1 means text match
    char input[1000]; // char array for text
    int i = 0; // counter
    int length = 0;
    while (text[i] != '\0') { // use character array to collect the input text
        input[i] = text[i];
        length++;
        i++;
    }
    
    i = 0;
    while (i < length) { // change all the capital letter in text to lower..
        if ('A' <= input[i] && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
        i++;
    }
    
    char pokename[1000]; // character array for pokemon name
    int namLength = 0;
    i = 0;
    while (pokemon[i] != '\0') {
        pokename[i] = pokemon[i];
        namLength++;
        i++;
    }
    
    i = 0;
    while (i < namLength) { // change it to lower case
        if ('A' <= pokename[i] && pokename[i] <= 'Z') {
            pokename[i] = pokename[i] - 'A' + 'a';       
        }    
        i++;
    }
    
    int e = 0;
    while (e < namLength && input[0] != pokename[e]) { // find first equal word 
        e++;
    }

    printf("%d||||||||%d||||||\%d\n",length,namLength,e);
    
    
    
    if (e == namLength) { // input text and pokemon name not match
        printf("TOTAL NOT MATCH!!!!!!!\n");
        //return 0;
    } else {  // pokemoname[e] == input[0]
        int check = 1; // counter to check are these characters all match (1 means match)
        int p = 0;
        while (p < length && e < namLength) { // length is the text word length
            if (input[p] != pokename[e]) {
                check = 0; // 0 means not match; 
                printf("TEXT not match AAAAAAA\n");
            }
            p++;
            e++;
        }
        
        if (check == 1) {
            printf("YEEES!MATCH!\n");
            //return 1;   // 1 means match
        } else {
            printf("Part euqal but still not match!!!!!!\n");
            //return 0;   // 0 means not match
        }   
    }   
}


int main(void) {
    char pokemon[] = "pikachu";
    char text[] = "";
    match(pokemon,text);
    return 0;
}
