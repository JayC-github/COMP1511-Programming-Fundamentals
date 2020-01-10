//Calculating Exam Marks

#include<stdio.h>

int main(void){
    double x,y; // x is the total number of marks in the exam, y is the mark student was awarded.
    double z; // z=0.0;
    printf("Enter the total number of marks in the exam: "); 
    scanf("%lf", &x);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf", &y);
    
    z = y/x*100;
    printf("The student scored %.0lf%% in this exam.\n", z);
    return 0;
}
