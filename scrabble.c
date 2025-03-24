#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//string LETTERS[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,Z};

int compute_score(char* word);
char* get_word(void);

int main(void)
{
    // Prompt the user for two words
    printf("Player1: ");
    char* word1 = get_word();
    //printf("\n");
    printf("Player2: ");
    char* word2 = get_word();
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

int compute_score(char* word)
{
    int score;
    // Compute and return score for word
    return score;
}

