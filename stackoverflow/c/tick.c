#include <stdio.h>

int main()
{
    char string[] = "       *      *     **   * * *  *";
    int line = 6, stop = 0, len = 8;
    for(line = 6; line > 0;line--){
        printf("%.*s\n", len, string + stop);
        stop = stop + len;
        --len;
    }
    return 0;
}
