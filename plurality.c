#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

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
bool vote(string name)
{
    for (int i = 0, c = candidate_count; i < c; i++)
    {
        //compare each name with the name the user gave and increases the vote count for the typed candidate
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //initialize the higest vote count
    int highest_vote_count = 0;

    //compare each of the vote counts for the candidates and if a candidate has a higher vote count than the current vote count, updates the global vote count to the new highest value
    for (int i = 0, c = candidate_count; i < c; i++)
    {
        if (candidates[i].votes >= highest_vote_count)
        {
            highest_vote_count = candidates[i].votes;
        }
    }

    //print the names of all the candidates that have an equal vote count to the highest vote count
    for (int i = 0, c = candidate_count; i < c; i++)
    {
        if (candidates[i].votes == highest_vote_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

