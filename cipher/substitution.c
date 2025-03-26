#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_for_duplicates(const char *key);
bool validate_key(const char *key);

int main(int argc, char* argv[])
{
char* key = argv[1];
validate_key(key);
}

bool check_for_duplicates(const char *key)
{
    bool seen[26] = {false};  // array of seen letters

    for (int i; key[i] != '\0'; i++)
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
        printf("Wrong key! Must be 26 letters!\n");
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