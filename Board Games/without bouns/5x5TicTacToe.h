
#ifndef _5X5TICTACTOE_H
#define _5X5TICTACTOE_H
#include "BoardGame_Classes.h"
int moves;
bool flag1 = false;

template <typename T>
class TicTacToe_Board : public Board<T>
{
public:
    TicTacToe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    void check_wins(int& x_wins, int& o_wins); 
};


template <typename T>
class TicTacToe_Player : public Player<T>
{
public:
        TicTacToe_Player (string name, T symbol);
        void getmove(int& x, int& y);
};

template <typename T>
class TicTacToe_Random_Player : public RandomPlayer<T>
{
public:
        TicTacToe_Random_Player (T symbol);
        void getmove(int &x, int &y);
};




//--------------------------------------- IMPLEMENTATION


#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
using namespace std;


// Constructor for TicTacToe_Board
template <typename T>
TicTacToe_Board<T>::TicTacToe_Board()
{
    this->rows = this->columns = 5;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}


template <typename T>
bool TicTacToe_Board<T>::update_board(int x, int y, T mark)
{
    // Only update if move is valid
    if(flag1)
    {
        this->n_moves++;
        moves = 0 ;
        flag1 = false;
        return true;
    }
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0))
    {
            this->n_moves++;
            moves = this->n_moves;
            this->board[x][y] = toupper(mark);
            return true;
    }
    return false;
}
// Display the board and the pieces on it
template <typename T>
void TicTacToe_Board<T>::display_board()
{
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n\n| ";
        for (int j = 0; j < this->columns; j++)
        {
            if(this->board[i][j] != 0)
            {
                cout << setw(4) << this->board[i][j]  << setw(4) << " |";
            }
            else
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << this->board[i][j] << " |";
            }
        }
        cout << "\n------------------------------------------";
    }
    int x_wins, o_wins;
    check_wins(x_wins, o_wins);
    cout << endl;
    cout << "The number of wins of X : " << x_wins << endl;
    cout << "The number of wins of O : " << o_wins << endl;
}
// Check rows, columns, and diagonals for wins
template <typename T>
void TicTacToe_Board<T>::check_wins(int& x_wins, int& o_wins) 
{
    x_wins = 0;
    o_wins = 0;
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->columns - 2; j++) 
        {
            if (this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2]) 
            {
                if (this->board[i][j] == 'X') x_wins++;
                else if (this->board[i][j] == 'O') o_wins++;
            }
        }
    }
    for (int i = 0; i < this->rows - 2; i++) 
    {
        for (int j = 0; j < this->columns; j++) 
        {
            if (this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j]) 
            {
                if (this->board[i][j] == 'X') x_wins++;
                else if (this->board[i][j] == 'O') o_wins++;
            }
        }
    }
    for (int i = 0; i < this->rows - 2; i++) 
    {
        for (int j = 0; j < this->columns - 2; j++) 
        {
            if (this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2]) 
            {
                if (this->board[i][j] == 'X') x_wins++;
                else if (this->board[i][j] == 'O') o_wins++;
            }
            if (this->board[i][j+2] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j]) 
            {
                if (this->board[i][j+2] == 'X') x_wins++;
                else if (this->board[i][j+2] == 'O') o_wins++;
            }
        }
    }
}

template <typename T>
bool TicTacToe_Board<T>::is_win()
{
    if (this->n_moves < 24) 
        return false;
    else if(this->n_moves == 25)
        return true;
    int x_wins, o_wins;
    check_wins(x_wins, o_wins);
    if(o_wins > x_wins)
        return true;
    else
        return false;
}

template <typename T>
bool TicTacToe_Board<T>::is_draw()
{
    if (this->n_moves < 24) 
        return false;

    int x_wins, o_wins;
    check_wins(x_wins, o_wins);
    return (x_wins == o_wins);
}

template <typename T>
bool TicTacToe_Board<T>::game_is_over()
{
    if (this->n_moves < 24) 
        return false;
    int x_wins, o_wins;
    check_wins(x_wins, o_wins);
    return (is_win() || is_draw());
}

// Constructor for TicTacToe_Player
template <typename T>
TicTacToe_Player<T>::TicTacToe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void TicTacToe_Player<T>::getmove(int& x, int& y)
{
    if(moves == 24)
    {
        flag1 = true;
        x = y = 5;
    }
    else
    {
        cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
        while (true) {
            cin >> x >> y;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }
    }
}

// Constructor for TicTacToe_Random_Player
template <typename T>
TicTacToe_Random_Player<T>::TicTacToe_Random_Player(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 5;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void TicTacToe_Random_Player<T>::getmove(int& x, int& y)
{
    if(moves == 24)
    {
        flag1 = true;
        x = y = 5;
    }
    x = rand() % this->dimension;  // Random number between 0 and 4
    y = rand() % this->dimension;
}

#endif //_5X5TICTACTOE_H
