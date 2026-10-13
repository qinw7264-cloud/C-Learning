#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximum numbers of voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Store each voter's ranked preferences
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidate structure
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Candidate array
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check command-line arguments
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Initialize candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    voter_count = get_int("Number of voters: ");

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Collect voter preferences
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Run the election
    while (true)
    {
        // Count votes
        tabulate();

        // Check for a winner
        if (print_winner())
        {
            break;
        }

        // Find minimum number of votes
        int min = find_min();

        // Check for a tie
        if (is_tie(min))
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }

            break;
        }

        // Eliminate candidates with minimum votes
        eliminate(min);

        // Reset votes for next round
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}


// 1. Record voter preferences
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}


// 2. Count votes for remaining candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j];

            if (!candidates[index].eliminated)
            {
                candidates[index].votes++;
                break;
            }
        }
    }
}


// 3. Check whether someone has won
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}


// 4. Find minimum votes among remaining candidates
int find_min(void)
{
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }

    return min;
}


// 5. Check whether all remaining candidates are tied
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }

    return true;
}


// 6. Eliminate candidates with minimum votes
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}