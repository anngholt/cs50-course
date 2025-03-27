#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[50];  // Name of candidate
    int votes;      // Number of votes
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(char* name);
void print_winner(void);

int main(int argc, char* argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality Candidate1 ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]); // Copy candidate name
        candidates[i].votes = 0;                 // Initialize votes to 0
    }

    // Get number of voters
    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[50];  // Buffer for user input
        printf("Vote: ");
        scanf("%s", name);  // Read input from user

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(char* name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // Compare strings
        {
            candidates[i].votes++; // Increase vote count
            return 1;  // Successful vote
        }
    }
    return 0;  // Vote not found
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;

    // Find the max vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print candidates with the max vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
