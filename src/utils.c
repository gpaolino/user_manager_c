#include <stdio.h>
#include <string.h>

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
        *pos = '\0';
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
