#include <stdio.h>

int main(void) {

    int width, height;

    printf("Enter height: ");
    scanf("%d", &height);
    printf("\nEnter width: ");
    scanf("%d", &width);
    printf("\n");

    for (int i = 1; i <= height; i++) {

        for (int j = 1; j <= width; j++) {

            if (i == 1 || i == height) {
                printf("X");
            }

            else {

                if (j == 1 || j == width) {
                    printf("X");
                }

                else {
                    printf(" ");
                }
                
            }
            
        }
        printf("\n");
    }
}