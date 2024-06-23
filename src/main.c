#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(void) {
    List *history = init_history();
    char input[256]; // Assuming a maximum input length of 256 characters
    char **tokens;

    while (1) {
        printf("> "); // Display the prompt
        fgets(input, sizeof(input), stdin); // Read input from the user

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for the end of input (Ctrl + D or Ctrl + Z in some systems)
        if (feof(stdin)) {
            printf("\n");
            break;
        }

        // Check if the input is a history recall command
        if (input[0] == '!' && strlen(input) > 1) {
            int id = atoi(input + 1);
            char *history_item = get_history(history, id);
            if (history_item) {
                printf("Recalled from history: %s\n", history_item);
                strcpy(input, history_item); // Replace input with the recalled history item
            } else {
                printf("No history item with id %d\n", id);
                continue;
            }
        }

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
