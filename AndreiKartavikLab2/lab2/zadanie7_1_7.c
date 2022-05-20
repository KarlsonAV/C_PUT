#include <stdio.h>


int main(void) {

    int height;

    printf("Enter height: ");
    scanf("%d", &height);
    printf("\n");

    int n = height * 2 - 1;

    for (int i = 1, left = n/2 + 1, right = left; i <= height; i++) {
        
        for (int j = 1; j <= n; j++) {
            
            if (j >= left && j <=right) {
                printf("X");
            }

            else {
                printf(" ");
            } 
        }

        left--; right++;
        printf("\n");
    }

}