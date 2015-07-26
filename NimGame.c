//
// Created by rooty on 7/25/15.
//

#include <stdio.h>

#define LINE_DELIMITER "---------------\n"
#define PRINT_BALLZ(X)({for (int i =0; i < (X); i++){printf("o");} printf("\n");})
#define SWITCH_PLAYER()({if (player==1){player = 2;} else{player = 1;}})
#define MAX_BALLZ_2_TAKE 3

int player = 1;
int box1Balls = 0;
int box2Balls = 0;


void printBoard() {
    printf(LINE_DELIMITER);
    printf("Box 1: ");
    PRINT_BALLZ(box1Balls);
    printf("Box 2: ");
    PRINT_BALLZ(box2Balls);
    printf(LINE_DELIMITER);

}

void getMove() {
    int *boxChoice = 0;
    printf("Player %d, i'ts your turn.\nPlayer %d, choose a box (1 or 2):", player, player);
    scanf("%1d", boxChoice);
    if (boxChoice != (int *) 1 & boxChoice != (int *) 2) {
        int *temp = 0;
        scanf("%1d", temp);
        getMove();
    } else {
        int *currentBox = 0;
        switch ((int)&boxChoice) {
            case 1:
                currentBox = &box1Balls;
                break;
            case 2:
                currentBox = &box2Balls;
                break;
        }
        printf("Player %d, how many balls do you want to take from box %d?", player, (int) boxChoice);
        int *numOfBallz = NULL;
        scanf("%1d", numOfBallz);
        if (numOfBallz < 0) {
            printf("Number of balls to take must be positive");
        } else if (numOfBallz > (int *) MAX_BALLZ_2_TAKE) {
            printf("Cannot take more than 3 balls at a time.");
        } else if (numOfBallz > (int) currentBox) {
            printf("Cannot take more balls than what's in the box");
        }
        else {
            *currentBox -= (int) &numOfBallz;
        }
    }

}

void startGame() {
    while (box1Balls != 0 || box2Balls != 0) {
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
        if (&pBox < 0) {
            printf("Number of balls in box must be positive.");
        }

    } while (pBox < 0);

}

int main() {

    getBalls(&box1Balls, 1);
    getBalls(&box2Balls, 2);

    startGame();

    printf("Player %d wins the game. \n", player);

    return 0;
}
