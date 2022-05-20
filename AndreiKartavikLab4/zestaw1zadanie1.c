#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char c;
    printf("Enter character: ");
    scanf("%c", &c);
    printf("\n");
    FILE *file;
    file = fopen("zadanie1.txt", "r");

    if (file == NULL) {
        printf("Unable to read the file\n");
        return 1;
    }

    char line[256];
    int n = 0;
    while(fgets(line, sizeof(line), file)) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == c) {
                n++;
            }
        }
    }
    fclose(file);

    printf("Result: %d\n", n);

}