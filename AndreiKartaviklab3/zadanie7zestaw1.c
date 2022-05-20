#include <stdio.h>
#include <string.h>

void read_reverse(char arr[], int n) {
    
    printf(" %c ", arr[n]);
    if (n == 0) {
        return;
    }

    read_reverse(arr, n-1);
}

int main(void) {

    int n = 0;
    printf("Enter your elements: ");
    char c[256];
    gets(c);
    read_reverse(c, strlen(c));
    printf("\n");
}