#include "gameboard_operations.h"

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
    //int empty[n][2];

    pos_t* empty_places = (pos_t*) malloc(n * n * sizeof(pos_t));
    if (empty_places == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    //find all 0s
    //when a new one is added remove it from memory and 
    int count = 0;
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(gameboard[j][i] == 0)
            {
                pos_t interim = {j, i};
                //interim.x = i;
                //interim.y = j;
                empty_places[count] = interim;
                ++count;
            }
            if(gameboard[j][i] == 2048)
            {
                print_gameboard();
                printf("wow you win!!1!\nending game..\n");
                exit(0);
            }
        }
    }

    if(count != 0)
    {
    int place = rand() % count;
    //int i = rand() % 4;

        if (rand() % 3 == 0)
        {
            gameboard[empty_places[place].y][empty_places[place].x] = 4;
        }
        else
        {
            gameboard[empty_places[place].y][empty_places[place].x] = 2;
        }

    } 
    free(empty_places);

    //if (rand() % 4 == 0)
    //{
    //    pick_random_tile();
    //}
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

void raw_move_left()
{
    slam_left();
    compress_left();
    slam_left();
}

void move_left()
{
    raw_move_left();
}

void move_up()
{
    transpose();
    raw_move_left();
    transpose();
}

void move_down()
{
    transpose();
    reverse();
    raw_move_left();
    reverse();
    transpose();
}

void move_right()
{
    reverse();
    raw_move_left();
    reverse();
}

void game_loop()
{
    int i = 1;
    while(i == 1)
    {
        //print_gameboard();
        char c;
        printf("[wasd]: ");
        scanf(" %c", &c);

        switch (c)
        {
        case 'a':
            move_left();
            break;

        case 's':
            move_down();
            break;

        case 'd':
            move_right();
            break;

        case 'w':
            move_up();
            break;

        default:
            break;
        }
        pick_random_tile();

        print_gameboard();
    }
}

/* Start of the application */
int main()
{
    srand(time(0));
    printf("\n****2048****\n");

    setup_gameboard();
    
    pick_random_tile();
    print_gameboard();


    game_loop();
}