#include <stdio.h>
#include <string.h>
#include <ctype.h>


void numeric(void) {
    FILE *fin, *fout;
    fin = fopen("zadanie7_i.txt", "r");
    fout = fopen("zadanie7_o.txt", "wt");
    if (fin == NULL || fout == NULL) {
        return;
    }
    int amount[100];
    for (int i = 0; i < 100; amount[i] = 0, i++);

    char line[256];
    int n = 0;
    int i = 0;
    while(fgets(line, sizeof(line), fin)) {
        for (; i < strlen(line); i++) {
            if (line[i] == '*') n++;
            else {
                break;
            }
        }
        amount[n]++;
        if (n == 1 && amount[n] > 1) {
            for (int j = 2; j < 100; amount[j] = 0, j++);
        }
        for (int j = 0; j < n; j++) {
            fprintf(fout, " ");
        }
        for (int j = 1; j <= n; j++) {
            fprintf(fout, "%d.", amount[j]);
        }
        for (;i<strlen(line);i++) {
            fprintf(fout, "%c", line[i]);
        }
        n = 0;
        i = 0;
    }
    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);
}

void alphabetic(void) {
    FILE *fin, *fout;
    fin = fopen("zadanie7_i.txt", "r");
    fout = fopen("zadanie7_o.txt", "wt");
    if (fin == NULL || fout == NULL) {
        return;
    }
    int amount[100];
    for (int i = 0; i < 100; amount[i] = 0, i++);

    char line[256];
    int n = 0;
    int i = 0;
    while(fgets(line, sizeof(line), fin)) {
        for (; i < strlen(line); i++) {
            if (line[i] == '*') n++;
            else {
                break;
            }
        }
        amount[n]++;
        if (n == 1 && amount[n] > 1) {
            for (int j = 2; j < 100; amount[j] = 0, j++);
        }
        for (int j = 0; j < n; j++) {
            fprintf(fout, " ");
        }
    
            if (n == 1) {
                fprintf(fout, "%c.", 64 + amount[n]);
            }
            else if (n == 2) {
                fprintf(fout, "%d.", amount[n]);
            }
            else if (n == 3) {
                fprintf(fout, "%c.", 96+amount[n]);
            }
            else if (n == 4) {
                fprintf(fout, "(%d)", amount[n]);
            }
            else if (n == 5) {
                fprintf(fout, "(%c)", 96+amount[n]);
            }
        
        for (;i<strlen(line);i++) {
            fprintf(fout, "%c", line[i]);
        }

        n = 0;
        i = 0;
    }
    printf("\n");

    fclose(fin);
    fclose(fout);
}

int main(void) {
    int a;
    printf("Would you like to make numeric transformation - 1, or alphabetic - 0?: ");
    scanf("%d", &a);
    printf("\n");
    a == 1? numeric():alphabetic();

}