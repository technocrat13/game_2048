#include "calculator_operations.h"

void setup_gameboard()
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            gameboard[j][i] = 0;
        }
    }
}

void print_gameboard()
{
    printf("\n");
    for (int j = 0; j < n; j++)
    {
        printf("       ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", gameboard[j][i]);
        }
        printf("\n");
    }
}

void pick_random_tile()
{

    int j = rand() % 4;
    int i = rand() % 4;
    if (gameboard[j][i] == 0)
    {
        if (rand() % 3 == 0)
        {
            gameboard[j][i] = 4;
        }
        else
        {
            gameboard[j][i] = 2;
        }
    }
    else
    {
        pick_random_tile();
    }
}

void slam_left()
{
    for (int j = 0; j < n; j++)
    {
        for (int t = 0; t < n - 1; t++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if(gameboard[j][i] == 0)
                {
                    gameboard[j][i] = gameboard[j][i + 1];
                    gameboard[j][i + 1] = 0;
                }
            }
        }
    }
}

void compress_left()
{
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n -1; i++)
        {
            if(gameboard[j][i] != 0 && gameboard[j][i] == gameboard[j][i + 1])
            {
                gameboard[j][i] = gameboard[j][i] * 2;
                gameboard[j][i + 1] = 0;
            }
        }
    }
}

void transpose()
{
    int interim_gameboard[n][n]; 
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            interim_gameboard[i][j] = gameboard[j][i];
        }
    }
    memcpy(&gameboard[0][0], &interim_gameboard[0][0], n * n * sizeof(interim_gameboard[0][0]));
    //gameboard =  *interim_gameboard;
}

void reverse()
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n / 2; i++)
        {
            int temp = gameboard[j][i];
            gameboard[j][i] = gameboard[j][n - i - 1];
            gameboard[j][n - i - 1] = temp;
        }
    }
}

/* Start of the application */
int main()
{
    srand(time(0));
    printf("\n****2048****\n");

    setup_gameboard();
    print_gameboard();
    pick_random_tile();
    pick_random_tile();
    print_gameboard();
    slam_left();
    print_gameboard();
    compress_left();
    print_gameboard();
    slam_left();
    print_gameboard();
    pick_random_tile();
    pick_random_tile();
    pick_random_tile();
    pick_random_tile();

    print_gameboard();
    printf("transpose: ");
    transpose();

    print_gameboard();
    printf("reverse: ");
    reverse();
    print_gameboard();
}