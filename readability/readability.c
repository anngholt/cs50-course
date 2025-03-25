#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char* get_text(void);
int get_number_of_sentences(char* text);

int main(void)
{

    // Prompt the user for some text
    char* text = get_text();
    int sentences = get_number_of_sentences(text);
    printf("Number of sentences:  %i\n", sentences);

    // Count the number of letters, words, and sentences in the text

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