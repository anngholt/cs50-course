#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_for_duplicates(const char *key);
bool validate_key(const char *key);
char* get_text(void);
char map_letter(char letter, const char *key);
void encrypt_text(char *text, const char *key);


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key \n");
        return 1;
    }

    char* key = argv[1];

    if (!validate_key(key))
    {
        return 1;
    }
    //prompt user for text
    char* plaintext = get_text();
    encrypt_text(plaintext, key);
    // Print the encrypted text
    printf("ciphertext: %s\n", plaintext);  // Output the encrypted text

    free(plaintext);

}

bool check_for_duplicates(const char *key)
{
    bool seen[26] = {false};  // array of seen letters

    for (int i = 0; key[i] != '\0'; i++)
    {
        char letter = tolower(key[i]);
        int index = letter - 'a';
        if (seen[index] == true)
        {
            return true; //duplicate!

        }
        seen[index] = true;
    }

return false;
}

bool validate_key(const char *key)
{
    //Ensure the key is exactly 26 characters long.
    int size = strlen(key);
    if (size != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }   
    //Ensure the key contains only alphabetic characters.
    for (int i = 0; key[i] != '\0'; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Wrong key!\n");
            return false;
        }
    }
    //Ensure the key does not have duplicate letters.
    if (check_for_duplicates(key) == true)
    {
        printf("Wrong key! Must not contain duplicates!\n");
        return false;
    }  
    return true; 
}

char* get_text(void)
{
    char *text = malloc(500);  // Allocate memory dynamically
    if (!text) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("plaintext: ");
    fgets(text, 500, stdin);
    return text;
}

char map_letter(char letter, const char *key)
{
    if (isalpha(letter))
    {
        bool is_upper = isupper(letter);
        int index = tolower(letter) - 'a';
        char mapped = key[index];

        return is_upper ? toupper(mapped) : tolower(mapped); 

    }
    return letter;

}

void encrypt_text(char *text, const char *key)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] = map_letter(text[i], key); // Replace each letter
    }
}