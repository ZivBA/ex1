//
// Created by rooty on 7/25/15.
//

#include <stdio.h>
//constants
#define MAX_BALLZ_2_TAKE 3
#define LINE_DELIMITER "---------------\n"

/**
 * macro that prints the balls in a certain box.
 */
#define PRINT_BALLZ(X)({for (int i =0; i < (X); i++){printf("o");} printf("\n");})
/**
 * macro that switches the player from 1 to 2 or 2 to 1.
 */
#define SWITCH_PLAYER()( (player==1) ? (player = 2) : (player = 1))

// global vars.
int player = 1;         // player defaults to player 1.
int box1Balls = 0;      // boxes default to 0.
int box2Balls = 0;

/**
 * helper method to print the board.
 */
void printBoard() {

    printf(LINE_DELIMITER);
    printf("Box 1: ");
    PRINT_BALLZ(box1Balls);
    printf("Box 2: ");
    PRINT_BALLZ(box2Balls);
    printf(LINE_DELIMITER);

}

/**
 * method that gets the move, validates box choice and processes the move.
 */
void getMove() {
    int boxChoice = (int)0;

    // get user input.
    printf("Player %d, i'ts your turn.\nPlayer %d, choose a box (1 or 2):\n", player, player);
    scanf("%1d", &boxChoice);

    // check if box choice is OK, then reference the box pointer to the actual box.
    if (boxChoice != 1 & boxChoice !=  2) {
        int *temp = 0;
        scanf("%1d", temp);
        getMove();
    } else {
        // pointer to a box.
        int *currentBox = 0;
        switch (boxChoice) {
            case 1:
                currentBox = &box1Balls;
                break;
            case 2:
                currentBox = &box2Balls;
                break;
        }
        int numOfBallz;
        int inValidMove = 1;

        while (inValidMove){
            printf("Player %d, how many balls do you want to take from box %d?\n", player, boxChoice);
            scanf("%10d", &numOfBallz);

            // check if pick is valid

            if (numOfBallz < 0) {
                printf("Number of balls to take must be positive.\n");
            } else if (numOfBallz > MAX_BALLZ_2_TAKE) {
                printf("Cannot take more than 3 balls at a time.\n");
            } else if (numOfBallz > *currentBox) {
                printf("Cannot take more balls than what's in the box.\n");
            }
            else {
                *currentBox -= numOfBallz;
                inValidMove = 0;
            }
        }
    }

}

void startGame() {
    while (box1Balls != 0 && box2Balls != 0) {
        printBoard();
        getMove();
        SWITCH_PLAYER();
    }

}


void getBalls(int *pBox, int boxNum) {
    do {
        printf("How many balls in box %d?\n", boxNum);
        scanf("%2d", pBox);
        getchar();
        if (*pBox < 0) {
            printf("Number of balls in box must be positive.\n");
        }

    } while (*pBox < 0);

}

int main() {

    getBalls(&box1Balls, 1);
    getBalls(&box2Balls, 2);

    startGame();

    printf("Player %d wins the game.\n", player);

    return 0;
}
