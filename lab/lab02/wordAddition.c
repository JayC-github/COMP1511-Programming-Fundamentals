//Word Addition challenge
//Jay 2019.02.28

#include<stdio.h>

int main(void){
    int x,y,z;
    
    printf("Please enter two integers: ");
    scanf("%d %d", &x,&y);
    z=x+y;
//first integer
    if(x <0 && x >= -10){
       printf("negative ");
    }
    if(x==0){
       printf("zero");
    }else if(x==1 || x==-1){
       printf("one");
    }else if(x==2 || x==-2){
       printf("two");
    }else if(x==3 || x==-3){
       printf("three");
    }else if(x==4 || x==-4){
       printf("four");
    }else if(x==5 || x==-5){
       printf("five");
    }else if(x==6 || x==-6){
       printf("six");
    }else if(x==7 || x==-7){
       printf("seven");
    }else if(x==8 || x==-8){
       printf("eight");
    }else if(x==9 || x==-9){
       printf("nine");
    }else if(x==10 || x==-10){
       printf("ten");
    }else{
       printf("%d",x);
    
    }
    
     printf(" + ");
//second integer    
     if(y <0 && y >= -10){
       printf("negative ");
    }
    if(y==0){
       printf("zero");
    }else if(y==1 || y==-1){
       printf("one");
    }else if(y==2 || y==-2){
       printf("two");
    }else if(y==3 || y==-3){
       printf("three");
    }else if(y==4 || y==-4){
       printf("four");
    }else if(y==5 || y==-5){
       printf("five");
    }else if(y==6 || y==-6){
       printf("six");
    }else if(y==7 || y==-7){
       printf("seven");
    }else if(y==8 || y==-8){
       printf("eight");
    }else if(y==9 || y==-9){
       printf("nine");
    }else if(y==10 || y==-10){
       printf("ten");
    }else{
       printf("%d",y);
    
    }
    
      printf("=");
//sum of two integers     
    if(z <0 && z>=-10){
       printf("negative ");
    }
    if(z==0){
       printf("zero");
    }else if(z==1 || z==-1){
       printf("one");
    }else if(z==2 || z==-2){
       printf("two");
    }else if(z==3 || z==-3){
       printf("three");
    }else if(z==4 || z==-4){
       printf("four");
    }else if(z==5 || z==-5){
       printf("five");
    }else if(z==6 || z==-6){
       printf("six");
    }else if(z==7 || z==-7){
       printf("seven");
    }else if(z==8 || z==-8){
       printf("eight");
    }else if(z==9 || z==-9){
       printf("nine");
    }else if(z==10 || z==-10){
       printf("ten");
    }else{
       printf("%d",z);
    
    }
      printf("\n");
      return 0;
}
