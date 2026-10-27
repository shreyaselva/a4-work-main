#include <stdio.h>
#include <stdlib.h>
#include "../vector/vect.h"
#include "tokens.h"

#define BUFFER_SIZE 1024

int main(void) {
    char buffer[BUFFER_SIZE];

    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        vect_t *tokens = tokenize(buffer);

        for (unsigned int i = 0; i < vect_size(tokens); i++) {
            printf("%s\n", vect_get(tokens, i));
        }

        vect_delete(tokens);
    }
    return 0;
}
