#include <stdio.h>

int main(void)
{
    int i = 0, c = 0;
    int amount[100], arr[100];
    for (int i = 0; i < 100; arr[i] = 0, amount[i] = 0, i++);
    FILE *in = fopen("zadanie8_i.txt", "r");
    FILE *out = fopen("zadanie8_o.txt", "w");

    if (in == NULL || out == NULL) {
        return 1;
    }

    if (in != NULL) {
        char line[BUFSIZ];
        
        while (fgets(line, sizeof line, in) != NULL) {
            char *start = line;
            int field;
            int n;
            
            while (sscanf(start, "%d%n", &field, &n) == 1) {
                
                amount[i] += 1;
                arr[i++] += field;
                c++;
                start += n;
            }
            i = 0;
            puts("");
        }
        
        fclose(in);
    }

    fprintf(out, "Suma: ");
    for (int i = 0; i < c / 2 + 1; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fprintf(out, "\nSrednia: ");
    for (int i = 0; i < c / 2 + 1; i++) {
            fprintf(out, "%.1f ", (float) arr[i] / amount[i]);
        }
    fclose(out);
    return 0;
}