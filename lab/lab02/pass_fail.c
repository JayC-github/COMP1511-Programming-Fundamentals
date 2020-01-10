//pass fail
//Jay
//2019.02.26

#include<stdio.h>

#define PASS_MARK 50
#define MAX_MARK 100

int main(void){
    int mark = 0;
    
    printf("Please enter your mark:");
    
    scanf("%d", &mark);
    
    if(mark > MAX_MARK) {
       printf("ERROR\n");
    } else if(mark >= PASS_MARK) {
       printf("PASS\n");    
    } else {
       printf("FAIL\n");
    }

    return 0;
}
