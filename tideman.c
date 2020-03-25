#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int p = 0; p < candidate_count; p++)
    {
        if (strcmp(name, candidates[p]) == 0)
        {
            ranks[rank] = p;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int p = 0; p < candidate_count - 1; p++)
    {
        for (int q = p + 1; q < candidate_count; q++)
        {
            preferences[ranks[p]][ranks[q]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int paircount = 0;
    for (int p = 0; p < candidate_count; p++)
    {
        for (int q = 0; q < candidate_count; q++)
        {
            if(p != q)
            {
                if (preferences[p][q] > preferences[q][p])
                {
                    pairs[paircount].winner = p;
                    pairs[paircount].loser = q;
                    paircount++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // (preferences[pairs[i].winner] - preferences[pairs[i].loser])
    for (int p = 0; p < MAX * (MAX - 1) / 2 ; p++)
    {
        for (int q = 0; q < MAX * (MAX - 1) / 2; q++)
        {
            pair temp;
            int p_diff = preferences[pairs[p].winner][pairs[p].loser] - preferences[pairs[p].loser][pairs[p].winner];
            int q_diff = preferences[pairs[q].winner][pairs[q].loser] - preferences[pairs[q].loser][pairs[q].winner];
            if (p_diff < q_diff)
            {
                temp = pairs[p];
                pairs[p] = pairs[q];
                pairs[q] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int checkcol = 0, checkrow = 1;
    for (int p = 0; p < MAX * (MAX - 1) / 2; p++)
    {
        for (int a = 0; a < candidate_count; a++)
        {
            for (int b = 0; b < candidate_count; b++)
            {
                if (locked[a][b] == true)
                checkcol = 1;
            }
            if (checkcol == 1)
            {
                checkrow++;
            }
        }
        if (checkrow != candidate_count)
        {
            locked[pairs[p].winner][pairs[p].loser] = true;
        }
        else
        {
            return;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int pos, q, p;
    for (q = 0; q < candidate_count; q++)
    {
        int flag = 0;
        for (p = 0; p < candidate_count; p++)
        {
            if (locked[p][q] == true)
            {
                flag = 1;
            }

        }
        if (flag == 0)
        {
            printf("%s", candidates[q]);
        }
    }
    return;
}

