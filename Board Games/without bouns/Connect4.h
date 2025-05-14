#ifndef _CONNECT4_H
#define _CONNECT4_H

#include "BoardGame_Classes.h"

template <typename T>
class Connect4_Board:public Board<T> {
public:
    Connect4_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class Connect4_Player : public Player<T> {
public:
    Connect4_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Connect4_Random_Player : public RandomPlayer<T>{
public:
    Connect4_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};


// ----------------------------------- IMPLEMENTATION


#include <bits/stdc++.h>


template <typename T>
Connect4_Board<T>::Connect4_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}


template <typename T>
bool Connect4_Board<T>::update_board(int x, int y, T mark) {
    // Check if column is valid
    if (y < 0 || y >= this->columns) {
        return false;
    }
    
    int row = -1;
    if (mark == 0) {
        for (int test = 0; test < this->rows; ++test) {
            if (this->board[test][y] != 0) { 
                row = test; 
                break;
            }
        }
        if (row == -1) {
            return false;
        }

        this->board[row][y] = 0;
        this->n_moves--;
        return true;
    }

    for (int test = this->rows - 1; test >= 0; --test) {
        if (this->board[test][y] == 0) { 
            row = test; 
            break;
        }
    }
    if (row == -1) {
        return false;
    }

    this->board[row][y] = toupper(mark);
    this->n_moves++;                     
    return true;
}



template <typename T>
void Connect4_Board<T>::display_board() {
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
        cout << "\n----------------------------------------------------------";
    }
    cout << endl;
}



template <typename T>
bool Connect4_Board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for(int j = 0; j < (this->columns)-3; j++) {
            if ((this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j+2] == this->board[i][j+3] && this->board[i][j] != 0)){
                return true;
            }
        }
    }

    // check columns
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < (this->rows - 3); i++) {
            if (this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j] && this->board[i+2][j] == this->board[i+3][j] && this->board[i][j] != 0) {
                return true;
            }
        }
    }

    // Check diagonals
    for(int i = 0; i < (this->rows)-3; i++) {
        for(int j = 0; j < (this->columns)-3; j++){
            if((this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2] && this->board[i+2][j+2] == this->board[i+3][j+3] && this->board[i][j] != 0)){
                return true;
            }
        }
    }
    // Check diagonals
    for(int i = 0; i < (this->rows)-3; i++) {
        for(int j = 3; j < (this->columns); j++){
            if((this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2] && this->board[i+2][j-2] == this->board[i+3][j-3] && this->board[i][j] != 0)){
                return true;
            }
        }
    }
    return false;
}

// Return true if 42 moves are done and no winner
template <typename T>
bool Connect4_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool Connect4_Board<T>::game_is_over() {
    return is_win() || is_draw();
}


// ------------------------------------------------------------------- Players

template <typename T>
Connect4_Player<T>::Connect4_Player(string name, T symbol) : Player<T>(name, symbol) {
    this->name = name;
    this->symbol = symbol;
}

template <typename T>
void Connect4_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter which column to play (0 to 6): ";
    while (true) {
        cin >> y;
        if (cin.fail()){
            cout << "Invalid input! Please enter a number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
    x = 0;
}

template <typename T>
Connect4_Random_Player<T>::Connect4_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 7;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Connect4_Random_Player<T>::getmove(int& x, int& y) {
    y = rand() % this->dimension;
    x = 0;
}


#endif 