#include <gameboard_operations.h>

/* Start of the application */
int main()
{
    srand(time(0));
    printf("\n****2048****\n");
    int gameboard[n][n];
    setup_gameboard(gameboard);
    
    pick_random_tile(gameboard);
    print_gameboard(gameboard);

    game_loop(gameboard);
}
