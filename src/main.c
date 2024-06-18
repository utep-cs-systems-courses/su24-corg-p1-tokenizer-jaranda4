#include <stdio.h>

int main() {
    char input[256]; // Assuming a maximum input length of 256 characters

    while (1) {
        printf("> "); // Display the prompt
        fgets(input, sizeof(input), stdin); // Read input from the user
        
        // Check for the end of input (Ctrl + D or Ctrl + Z in some systems)
        if (feof(stdin)) {
            printf("\n");
            break;
        }

        // Echo the input back to the user
        printf("%s", input);
    }

    return 0;
}
