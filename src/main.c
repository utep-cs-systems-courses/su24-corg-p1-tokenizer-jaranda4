#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(void) {
    char input[256]; // Assuming a maximum input length of 256 characters
    List *history = init_history();
    char **tokens;
    
    while (1) {
        printf("> "); // Display the prompt
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break; // End of input (Ctrl + D or Ctrl + Z)
        }

        if (input[0] == '\n') continue; // Skip empty input

        // Add input to history
        add_history(history, input);

        // Tokenize the input
        tokens = tokenize(input);

        // Print tokens
        print_tokens(tokens);

        // Free tokens
        free_tokens(tokens);
    }

    // Print history before exiting
    print_history(history);

    // Free history list
    free_history(history);

    return 0;
}
