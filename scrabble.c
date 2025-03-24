#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(char* word);
char* get_word(void);
int letter_to_number(char letter);

int main(void)
{
    // Prompt the user for two words
    printf("Player1: ");
    char* word1 = get_word();
    //printf("\n");
    printf("Player2: ");
    char* word2 = get_word();

    // pring points (temp)
    for (int i = 0, size = strlen(word1); i < size; i++)
    {
        printf("%i\n", i);
    }




    //printf("\n");

    // Compute the score of each word
    //int score1 = compute_score(word1);
    //int score2 = compute_score(word2);

    // Print the winner   
}

char* get_word(void)
{
    static char word[100];
    scanf("%99s", word);
    return word;
}

int letter_to_number(char letter)
{
    if(isupper(letter))
    {
        return letter - 'A' + 1;
    }
    if (islower(letter))
    {
        return letter - 'a' + 1;
    }
return -1;
}

int compute_score(char* word)
{
    int score;
    // Compute and return score for word
    return score;
}

