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
    // Count the number of letters, words, and sentences in the text
    char* text = get_text();
    int sentences = get_number_of_sentences(text);
    int letters = get_number_of_letters(text);
    int words = get_number_of_words(text);

    // Compute the Coleman-Liau index
    float coleman_liau_index = 0.0588 * letters/words * 100 - 0.296 * sentences/words * 100 - 15.8;
    if (coleman_liau_index <= 0)
    {
        printf("Before grade 1\n");
    } else if (coleman_liau_index >= 16)
    {
        printf("Grade 16+\n");
    } else
    {
        printf("Grade %d\n", (int) round(coleman_liau_index));
    }   
}

char* get_text(void)
{
    static char text[500]; 
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);  
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