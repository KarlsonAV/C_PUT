#include <stdio.h>

int main(void)
{
    FILE *in = fopen("zadanie10_i.txt", "r");
    FILE *out = fopen("zadanie10_o.txt", "w");

    if (in == NULL || out == NULL) {
        return 1;
    }

    if (in != NULL) {
        char line[BUFSIZ];
        int sum = 0;
        while (fgets(line, sizeof line, in) != NULL) {
            char *start = line;
            int field;
            int n;
            
            
            while (sscanf(start, "%d%n", &field, &n) == 1) {
                sum += field;
                fprintf(out, "|%d", field);
                start += n;
            }
            fprintf(out, "|%d\n", sum);
            sum = 0;
            puts("");
        }
        
        fclose(in);
    }
    fclose(out);
    return 0;
}