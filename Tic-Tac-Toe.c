#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

char boardLayout[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //Array represents the board
char choice; //The location the player decides to place their mark
char symbol; //The mark of the current player
int player = 1; //Counts up with each turn
bool ended = false; //Checks if the game has ended

char getValidInput(); //Takes and validates an input
void updateBoard(char input); //Updates the board with the given input
void drawBoard(); //Draws the board
void printOutcome(int result); //Prints the result of a game
int evalBoard(); //Checks if the game is ended and how it ended

int main() 
{
    printf("Welcome to tic-tac-toe! \n"); //Welcome message
    printf("**********************  \n\n");
    drawBoard(); //Starting board
    printf("\n");
    
    //While the game has not ended
    while(!ended) {
        drawBoard();
        //Take an input
        choice = getValidInput();
        //Quit the game if a q is typed in
        if (choice == 'q') {
            printf("Game quit");
            exit(1);
        } else {
            //Update the board
            updateBoard(choice);
        }
        //Draw the new board and increment player
        drawBoard();
        player++;
        
        //Check if the game is over
        if (evalBoard() != 0) {
            ended = true;
        }
    }
    
    //Once the game is over, print the result
    printOutcome(evalBoard());
    return 0;
}

char getValidInput() {
    char input;
    
    //Set the symbol according to the player
    if ((player + 1) % 2 + 1 == 1)
        symbol = 'X';
    
    else if ((player + 1) % 2 + 1 == 2)
        symbol = 'O';
        
    else {
        printf("Fatal Error VI\n");
        return 'q';
    }
    
    //Loop until a return is given, ask for the input
    while (1) {
        printf("%c - Which square? [1-9] \n", symbol);
        scanf("%c", &input);
        getchar();
    
        //If the input is valid and the square is empty, return it
        if (input == '1' && boardLayout[1] == '1')
            return input;
            
        else if (input == '2' && boardLayout[2] == '2')
            return input;
            
        else if (input == '3' && boardLayout[3] == '3')
            return input;
            
        else if (input == '4' && boardLayout[4] == '4')
            return input;
            
        else if (input == '5' && boardLayout[5] == '5')
            return input;
            
        else if (input == '6' && boardLayout[6] == '6')
            return input;
            
        else if (input == '7' && boardLayout[7] == '7')
            return input;
            
        else if (input == '8' && boardLayout[8] == '8')
            return input;
            
        else if (input == '9' && boardLayout[9] == '9')
            return input;
            
        else if (input == 'q')
            return input;
            
        //If it is not valid, but it is a number, alert the player that the space is occupied
        else if (input == '1' || input == '2' || input == '3' || input == '4' || input == '5' || input == '6' || input == '7' || input == '8' || input == '9')
            printf("Space Occupied\n");
        
        //Otherwise, alert the player that the input is invalid
        else if (true)
            printf("Invalid Input\n");
    }
}

void updateBoard(char input) {
    
    //Once it recieves an input, set the space on the board to the symbol of the current player
    if (input == '1' && boardLayout[1] == '1')
        boardLayout[1] = symbol;
            
    else if (input == '2')
        boardLayout[2] = symbol;
            
    else if (input == '3')
        boardLayout[3] = symbol;
            
    else if (input == '4')
        boardLayout[4] = symbol;
            
    else if (input == '5')
        boardLayout[5] = symbol;
            
    else if (input == '6')
        boardLayout[6] = symbol;
            
    else if (input == '7')
        boardLayout[7] = symbol;
            
    else if (input == '8')
        boardLayout[8] = symbol;
            
    else if (input == '9')
        boardLayout[9] = symbol;
}

void drawBoard() {
    //Clear the console then draw the board
    system("clear");
    printf("\n");
    printf("    |   |\n");
    printf("  %c | %c | %c\n", boardLayout[1], boardLayout[2], boardLayout[3]);
    printf(" ___|___|___\n");
    printf("    |   |\n");
    printf("  %c | %c | %c\n", boardLayout[4], boardLayout[5], boardLayout[6]);
    printf(" ___|___|___\n");
    printf("    |   |\n");
    printf("  %c | %c | %c\n", boardLayout[7], boardLayout[8], boardLayout[9]);
    printf("    |   |\n");
    printf("\n");
}

void printOutcome(int result) {
    //Print the outcome based on the result
    if (result == 1)
        printf("X Wins!");
    else if (result == 2)
        printf("O Wins!");
    else if (result == 3)
        printf("Cat game!");
}

int evalBoard() {
    //Check for every possible winning combination
    if (boardLayout[1] == boardLayout[2] && boardLayout[2] == boardLayout[3]) {
        //If it is made up of X's, X won.
        if (boardLayout[1] == 'X') {
            return 1;
        //If it is made up of Y's, Y won.
        } else if (boardLayout[1] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[4] == boardLayout[5] && boardLayout[5] == boardLayout[6]) {
        if (boardLayout[4] == 'X') {
            return 1;
        } else if (boardLayout[4] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[7] == boardLayout[8] && boardLayout[8] == boardLayout[9]) {
        if (boardLayout[7] == 'X') {
            return 1;
        } else if (boardLayout[7] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[1] == boardLayout[4] && boardLayout[4] == boardLayout[7]) {
        if (boardLayout[1] == 'X') {
            return 1;
        } else if (boardLayout[1] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[2] == boardLayout[5] && boardLayout[5] == boardLayout[8]) {
        if (boardLayout[2] == 'X') {
            return 1;
        } else if (boardLayout[2] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[3] == boardLayout[6] && boardLayout[6] == boardLayout[9]) {
        if (boardLayout[3] == 'X') {
            return 1;
        } else if (boardLayout[3] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[1] == boardLayout[5] && boardLayout[5] == boardLayout[9]) {
        if (boardLayout[1] == 'X') {
            return 1;
        } else if (boardLayout[1] = 'O') {
            return 2;
        } else {
            return -1;
        }
    } else if (boardLayout[3] == boardLayout[5] && boardLayout[5] == boardLayout[7]) {
        if (boardLayout[3] == 'X') {
            return 1;
        } else if (boardLayout[3] = 'O') {
            return 2;
        } else {
            return -1;
        }
    //If no one won, but all squares are filled it is a draw.
    } else if (boardLayout[1] != '1' && boardLayout[2] != '2' && boardLayout[3] != '3' && boardLayout[4] != '4' && boardLayout[5] != '5' && boardLayout[6] != '6' && boardLayout[7] != '7' && boardLayout[8] != '8' && boardLayout[9] != '9') {
        return 3;
    //If no one won and it is not a draw, the game is ongoing
    } else {
        return 0;
    }
}
