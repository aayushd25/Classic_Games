#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " | ";
            }
            std::cout << "\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false; // Invalid move
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true; 
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true; 
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true; 
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true; 
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;

    std::cout << "Tic Tac Toe Game\n";
    game.printBoard();

    for (int turn = 0; turn < 9; ++turn) {
        int row, col;
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        std::cin >> row >> col;

        while (!game.makeMove(row, col)) {
            std::cout << "Invalid move. Try again: ";
            std::cin >> row >> col;
        }

        game.printBoard();

        if (game.checkWin()) {
            std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            return 0;
        }

        game.switchPlayer();
    }

    std::cout << "It's a draw!\n";
    return 0;
}
