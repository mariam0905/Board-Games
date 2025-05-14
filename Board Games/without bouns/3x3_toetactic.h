#ifndef _3X3_TOETACTIC_H
#define _3X3_TOETACTIC_H
#include "BoardGame_Classes.h"
bool flag = false;
char symbol;

template <typename T>
class toetactic_Board:public Board<T> 
{
    public:
        toetactic_Board ();
        bool update_board (int x , int y , T symbol);
        void display_board () ;
        bool is_win() ;
        bool is_draw();
        bool game_is_over();
};

template <typename T>
class toetactic_Player : public Player<T> 
{
    public:
        toetactic_Player (string name, T symbol);
        void getmove(int& x, int& y) ;

};

template <typename T>
class toetactic_Random_Player : public RandomPlayer<T>
{
    public:
        toetactic_Random_Player (T symbol);
        void getmove(int &x, int &y) ;
};


//--------------------------------------- IMPLEMENTATION



#include <iostream>
#include <iomanip>
#include <cctype> 
using namespace std;


// Constructor for toetactic_Board
template <typename T>
toetactic_Board<T>::toetactic_Board() 
{
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) 
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) 
        {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool toetactic_Board<T>::update_board(int x, int y, T mark) 
{
    if(flag == true)
        return true;
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) 
    {
        
        this->n_moves++;
        this->board[x][y] = toupper(mark);
        symbol = toupper(mark);
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void toetactic_Board<T>::display_board()
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
        cout << "\n--------------------------";
    }
    cout << endl;
}

template <typename T>
bool toetactic_Board<T>::is_win() 
{
    Player<T>* players[2];
    if(flag == true)
    {
        flag = false;
        return true;
    }
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) 
    {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) 
        {
            flag = true;
            if(symbol == 'O')
                cout << "The first player (playing with X)" << " wins\n";
            return false;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) 
    {
        flag = true;
        if(symbol == 'O')
            cout << "The first player (playing with X)" << " wins\n";
        return false;
    }
    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool toetactic_Board<T>::is_draw() 
{
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool toetactic_Board<T>::game_is_over() 
{
    return (is_win() || is_draw());
}

// Constructor for toetactic_Player
template <typename T>
toetactic_Player<T>::toetactic_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void toetactic_Player<T>::getmove(int& x, int& y) 
{
    if(flag == true)
        x = y = 3;
    else
    {
        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
        while (true) 
        {
            cin >> x >> y;
            if (cin.fail())
            {
                cout << "Invalid input! Please enter a number\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
                break;
        }
    }
}

// Constructor for toetactic_Random_Player
template <typename T>
toetactic_Random_Player<T>::toetactic_Random_Player(T symbol) : RandomPlayer<T>(symbol) 
{
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void toetactic_Random_Player<T>::getmove(int& x, int& y) 
{
    if(flag == true)
        x = y = 3;
    else
    {
        x = rand() % this->dimension;  // Random number between 0 and 2
        y = rand() % this->dimension;   
    }
}


#endif