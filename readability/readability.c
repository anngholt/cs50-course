#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char* get_text(void);
int get_number_of_sentences(char* text);
int get_number_of_letters(char* text);
int get_number_of_words(char* text);

int main(void)
{

    // Prompt the user for some text
    // Count the number of letters, words, and sentences in the text
    char* text = get_text();
    int sentences = get_number_of_sentences(text);
    int letters = get_number_of_letters(text);
    int words = get_number_of_words(text);
    printf("Number of sentences:  %i\n", sentences);
    printf("Number of letters:  %i\n", letters);
    printf("Number of words:  %i\n", words);

    

    // Compute the Coleman-Liau index

    // Print the grade level
}

char* get_text(void)
{
    static char text[500]; // Increased size to allow longer input
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin); // Use fgets instead of scanf to read full sentences
    return text;
}


int get_number_of_sentences(char* text)
{
    int count = 0;
    int size = strlen(text);
    for (int i = 0; i < size; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
return count;
}

int get_number_of_letters(char* text)
{
    int count = 0;
    int size = strlen(text);
    for (int i = 0; i < size; i++)
    {
        if (isalpha(text[i]))  // Check if the character is a letter
        {
            count++;
        }
    }
return count;
}

int get_number_of_words(char* text)
{
    int count = 1;
    int size = strlen(text);
    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')  // Check if the character is a space
        {
            count++;
        }
    }
return count;
}
