#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int automorphic(int num) {
    int sqrt, temp, last;
    int n = 0;
 
    sqrt = num*num;
    temp = num;
 
    while(temp>0){
        n++;
        temp = temp/10;
    }
 
    int den = floor(pow(10,n));
    last = sqrt % den;
 
    if (last == num) {
        return 1;
    }
 
    return 0;
}


int main(void) {
    int a,b;
    printf("Enter a: ");
    scanf("%d", &a);
    
    printf("\nEnter b: ");
    scanf("%d", &b);
    printf("\n");

    if (a > b) {
        printf("Error occured\n");
        return 0;
    }

    for (; a<=b ; a++) {
        if (automorphic(a) == 1) {
            printf("%d is automorphic\n", a);
        }
    }

}