#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* get_text(void);



int main(int argc, char *argv[]) {
    // Make sure the user provided exactly one argument
    if (argc != 2) {
        printf("Usage: ./program <key>\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; argv[1][i] != '\0'; i++) { 
        if (!isdigit(argv[1][i])) {  
            printf("Not a valid key\n");
            return 1;  // Exit immediately if an invalid character is found
        }
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    char* text = get_text();

    // For each character in the plaintext:
    int size = strlen(text);
    char incrypted_text[size + 1];  // Make sure to leave space for the null terminator
    incrypted_text[size] = '\0';  // Null-terminate the string

    for (int i = 0; i < size; i++) {
        if (isalpha(text[i])) {  // Check if the character is a letter
            if (isupper(text[i])) {  // For uppercase letters
                incrypted_text[i] = (text[i] - 'A' + key) % 26 + 'A';
            } else {  // For lowercase letters
                incrypted_text[i] = (text[i] - 'a' + key) % 26 + 'a';
            }
            // Print the encrypted letter
            printf("%c", incrypted_text[i]);
        } else {
            // For non-alphabet characters, just copy them directly
            incrypted_text[i] = text[i];
            // Print the non-alphabet character
            printf("%c", incrypted_text[i]);
        }
    }
    
}

char* get_text(void)
{
    static char text[500]; 
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);  
    return text;
}