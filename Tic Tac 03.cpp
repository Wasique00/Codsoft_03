//Tic Tac toe 

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Function to play the game
void playGame() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Create a 3x3 grid as the game board
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    // Assign "X" and "O" to two players
    char player = (rand() % 2 == 0) ? 'X' : 'O';

    // Main game loop
    while (true) {
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << player << ", enter your move (row and column, 1-3): ";
        cin >> row >> col;

        // Make sure the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the game board with the player's move
        board[row - 1][col - 1] = player;

        // Check if the current player has won
        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        // Determine if the game is a draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw." << endl;
            break;
        }

        // Switch the current player
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;

    do {
        playGame();

        // Ask if the players want to play another game
        cout << "Do you want to play again (y/n)? ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

