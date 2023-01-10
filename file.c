#include <stdio.h>
int main() {
        FILE * fp;
        char c;
        printf("File Handling\n");
        fp = fopen("demo.txt", "w");
        while ((c = getchar()) != ' ') {
            putc(c, fp);
        }
        fclose(fp);
        printf("Data Entered:\n");
        fp = fopen("demo.txt", "r"); //prints what user entered
        printf("1. ");
        int i = 2; //starts at 2 because already prints 1
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
            if (c=='\n'){
                printf("%d. ",i);
                i++;
            }
        }
        fclose(fp); //closes and prints
        printf("\n");
        return 0;
    }
