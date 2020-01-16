//Jay z5261536
//2019.03.24

#include<stdio.h>
#include<math.h>

double EuclideanDistance(int length, int vector1[length], int vector2[length]);

int main(void) {
    int length;
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    printf("Enter vector 1: ");
    int vector1[length];
    int i=0;
    while (i < length) {
        scanf("%d", &vector1[i]);
        i++;
    }
    
    printf("Enter vector 2: ");
    int vector2[length];
    int j=0;
    while (j < length) {
        scanf("%d", &vector2[j]);
        j++;
    }
    
    printf("Euclidean distance = %lf\n", EuclideanDistance(length, vector1, vector2));
    
    return 0;       
}

double EuclideanDistance(int length, int vector1[length], int vector2[length]){
    int a = 0;
    int total = 0;
    double distance;
    while(a < length){
        total += (vector1[a]-vector2[a])*(vector1[a]-vector2[a]);
        a++;
    }
    distance = sqrt(total);
    return distance;    
}  
 
