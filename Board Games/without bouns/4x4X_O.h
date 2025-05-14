
#ifndef _4x4X_O_H
#define _4x4X_O_H

#include "BoardGame_Classes.h"


template <typename T>
class X4_O4_Board:public Board<T> {
public:
    X4_O4_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class X4_O4_Player : public Player<T> {
public:
    X4_O4_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
    void getcurrent();

};

template <typename T>
class X4_O4_Random_Player : public RandomPlayer<T>{
public:
    X4_O4_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
    void getcurrent();
};



int ca ,cb;

//--------------------------------------- IMPLEMENTATION

#include <bits/stdc++.h>

using namespace std;

// Constructor for X4_O4_Board
template <typename T>
X4_O4_Board<T>::X4_O4_Board() {
    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->board[0][1] = this->board[0][3] = this->board[3][0] = this->board[3][2] = 'X' ;
    this->board[0][0] = this->board[0][2] = this->board[3][1] = this->board[3][3] = 'O' ;
    this->n_moves = 0;
}

template <typename T>
bool X4_O4_Board<T>::update_board(int x, int y, T mark) {
    
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)){
        if(this->board[ca][cb] == mark && !(ca < 0 || ca >= this->rows || cb < 0 || cb >= this->columns)){
            if ((abs(ca - x) == 1 && cb == y) || (abs(cb - y) == 1 && ca == x)) {
                if(x == ca || y == cb){
                    if (mark == 0){
                        this->n_moves--;
                        this->board[x][y] = 0;
                    }
                    else{
                        this->n_moves++;
                        this->board[x][y] = toupper(mark);
                        this->board[ca][cb] = 0;
                    }   
                    return true;
                }
            }
        }
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void X4_O4_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool X4_O4_Board<T>::is_win() {
   // Check rows
    for (int i = 0; i < this->rows; i++) {
        for(int j = 0; j < (this->columns)-2; j++) {
            if ((this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j] != 0)){
                return true;
            }
        }
    }

    // check columns
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < (this->rows) - 2; i++) {
            if (this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j] && this->board[i][j] != 0) {
                return true;
            }
        }
    }

    // Check diagonals
    for(int i = 0; i < (this->rows)-2; i++) {
        for(int j = 0; j < (this->columns)-2; j++){
            if((this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2] && this->board[i][j] != 0)){
                return true;
            }
        }
    }
    // Check diagonals
    for(int i = 0; i < (this->rows)-2; i++) {
        for(int j = 3; j < (this->columns); j++){
            if((this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2] && this->board[i][j] != 0)){
                return true;
            }
        }
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool X4_O4_Board<T>::is_draw() {
    return 0;
}

template <typename T>
bool X4_O4_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X4_O4_Player
template <typename T>
X4_O4_Player<T>::X4_O4_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X4_O4_Player<T>::getmove(int& x, int& y) {
    this->getcurrent();
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
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

template <typename T>
void X4_O4_Player<T>::getcurrent(){
    int a , b;
    cout << "please enter which one do you want to move (x , y): ";

    while (true) {
            cin >> a>> b;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }
    ca = a;
    cb = b;
}

// Constructor for X4_O4_Random_Player
template <typename T>
X4_O4_Random_Player<T>::X4_O4_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void X4_O4_Random_Player<T>::getmove(int& x, int& y) {
    this->getcurrent();
    x = rand() % this->dimension;  // Random number between 0 and 3
    y = rand() % this->dimension;
}

template <typename T>
void X4_O4_Random_Player<T>::getcurrent(){
    ca = rand() % this->dimension;
    cb = rand() % this->dimension;
}







#endif //_4x4X_O_H

