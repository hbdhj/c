#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char fileName1[] = "test.txt";
    char fileName2[] = "words.txt";
    FILE *f1 = fopen(fileName1, "r");
    FILE *f2 = fopen(fileName2, "w");
    char buf[80];
    while(fgets(buf, 80, f1)!=NULL) {
        printf("%s", buf);
        int i = 0;
        int s = 0;
        while(buf[i]!='\0') {
            if (buf[i]==' ') {
                char* word = malloc(sizeof(char)*(i-s));
                memcpy(word, buf+s, i-s);
                fprintf(f2, "word: %s\n", word);
                fflush(f2);
                i++;
                s=i;
            } else {
                i++;
            }
        }
        if (s<i) {
            char* word = malloc(sizeof(char)*(i-s));
            memcpy(word, buf+s, i-s);
            fprintf(f2, "word: %s", word);
            fflush(f2);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
