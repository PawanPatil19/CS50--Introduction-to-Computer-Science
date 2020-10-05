#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];
bool lock=true;

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
void validateLock(int j);
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
    // TODO
    for(int i=0;i<candidate_count;i++)
    {
        if(strcmp(candidates[i],name)==0)
        {
            ranks[rank]=i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    for(int i=0;i<candidate_count;i++ )
    {
        for(int j=i+1;j<candidate_count;j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }

    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

      for(int i=0;i<candidate_count;i++)
      {
          for(int j=i+1;j<candidate_count;j++)
          {
              if(preferences[i][j]>preferences[j][i])
              {
                  pairs[pair_count].winner=i;
                  pairs[pair_count].loser=j;
                  pair_count++;
              }
              if(preferences[i][j]<preferences[j][i])
              {
                  pairs[pair_count].winner=j;
                  pairs[pair_count].loser=i;
                  pair_count++;
              }

          }
      }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int a;
    pair temp;
    for (int i = 0; i < pair_count; ++i)
        {
            int b=preferences[pairs[i].winner][pairs[i].loser];
            for(int j=i+1;j<pair_count;j++)
            {
                int c=preferences[pairs[j].winner][pairs[j].loser];
                   if(b<c)
                   {

                        temp=pairs[i];
                        pairs[i]=pairs[j];
                        pairs[j]=temp;
                   }

            }


        }
    return;
}




void validateLock(int j)
{
    if (j == 0)
    {
        return;
    }

    int r = 0;
    bool rank[j];
    for (int i = 0; i < j; i++)
    {
        rank[i] = false;
    }

    // checks all the submatrixes up to a single square using recursion
    validateLock(j - 1);

    for (int i = 0; i < j; i++)
    {
        for (int k = 0; k < j; k++)
        {
            if (locked[i][k] == true)
            {
                rank[i] = true;
            }
        }
    }

    for (int i = 0; i < j; i++)
    {
        if (rank[i] == true)
        {
            r++;
        }
    }

    // if the rank is max the lock is canceled
    if (r == j)
    {
        lock = false;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;

        validateLock(candidate_count);
        // if the validateLock function found a cycle we reverse the lock
        if (!lock)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
        lock = true;
    }
}


// Print the winner of the election
void print_winner(void)
{
    // TODO

   int rank;

    for (int i = 0; i < candidate_count; i++)
    {
        rank = 0;
        for (int k = 0; k < candidate_count; k++)
        {
            if (locked[k][i] == false)
            {
                rank++;
            }
        }

        // Prints all the names that are the source of the graph
        if (rank == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
}

