#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    int candidateFound;
    bool goodVote;
    bool isOK;

    for(int i=0; i<candidate_count; i++)
    {
        candidateFound = strcmp(name, candidates[i].name);

        isOK = (abs(candidateFound) <= candidate_count);


        if(candidateFound == 0)
        {
            goodVote = true;
            candidates[i].votes += 1;

        }
        else if(!isOK)
        {
           /* printf("Invalid vote.\n"); */
           goodVote = false;
        }


    }

    // printf("Vote Counted for: %s\nCF: %i\n", name, candidateFound) ;

    if(!goodVote)
    {
        return false;
    }
    else
        return true;

}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int maxVotes = 0;
    for(int i=0; i<candidate_count; i++)
    {
        maxVotes = (candidates[i].votes > maxVotes) ? (candidates[i].votes) : (maxVotes);
        printf("Candidate: %s\t Score:%d\n", candidates[i].name, candidates[i].votes);

    }


    for(int i=0; i<candidate_count; i++)
    {
        if(candidates[i].votes == maxVotes)
        {
            printf("\nWinner is: %s\n", candidates[i].name);
        }
    }

    return;
}
