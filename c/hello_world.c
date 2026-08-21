#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *text = (char *)malloc(4 * sizeof(char));

    strcpy(text, "ola"); // 'o', 'l', 'a', '\0'

    printf("%s ", (char *)text);

    free(text);
    return 0;
}