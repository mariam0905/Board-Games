#ifndef _PYRAMID_XO_TICTACTOE_H
#define _PYRAMID_XO_TICTACTOE_H


#include "BoardGame_Classes.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>
class PyramidXOTicTacToeBoard : public Board<T>
{
public:
    PyramidXOTicTacToeBoard();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class PyramidXOTicTacToePlayer : public Player<T>
{
public:
    PyramidXOTicTacToePlayer(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class PyramidXOTicTacToeRandomPlayer : public RandomPlayer<T>
{
public:
    PyramidXOTicTacToeRandomPlayer(T symbol);
    void getmove(int& x, int& y);
};



//--------------------------------------- IMPLEMENTATION

template <typename T>
PyramidXOTicTacToeBoard<T>::PyramidXOTicTacToeBoard() {
    this->rows = 3;
    this->columns = 5;
    this->board = new char*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            if ((i == 0 && (j == 0 || j == 1|| j == 3|| j == 4)) || (i == 1 && (j == 0 || j == 4))) {
                this->board[i][j] = ' ';
            } else {
                this->board[i][j] = 0;
            }
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool PyramidXOTicTacToeBoard<T>::update_board(int x, int y, T symbol) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns)){
        if(this->board[x][y] == 0 || (symbol == 0 && this->board[x][y] != ' ') ){
            if (symbol == 0){
                this->n_moves--;
                this->board[x][y] = 0;
                return true;
            }
            if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns)) {
                this->n_moves++;
                this->board[x][y] = toupper(symbol);
                return true;
            }
        }
    }
    return false;
}

template <typename T>
void PyramidXOTicTacToeBoard<T>::display_board() {
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
}

template <typename T>
bool PyramidXOTicTacToeBoard<T>::is_win() {
    if ((this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[0][2] != 0) ||
        (this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4] && this->board[0][2] != 0) ||
        (this->board[1][1] == this->board[1][2] && this->board[1][2] == this->board[1][3] && this->board[1][1] != 0) ||
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 0) ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0)) {
        return true;
    }
    return false;
}

template <typename T>
bool PyramidXOTicTacToeBoard<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool PyramidXOTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
PyramidXOTicTacToePlayer<T>::PyramidXOTicTacToePlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void PyramidXOTicTacToePlayer<T>::getmove(int& x, int& y) 
{
        cout << "\nPlease enter your move (x and y) separated by spaces: ";
        cin >> x >> y;
}

template <typename T>
PyramidXOTicTacToeRandomPlayer<T>::PyramidXOTicTacToeRandomPlayer(T symbol) : RandomPlayer<T>(symbol)
 {
    this->symbol = symbol;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void PyramidXOTicTacToeRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 5;
}

#endif // _PYRAMID_XO_TICTACTOE_H
