#ifndef NUMERICAL_H
#define NUMERICAL_H

#include "BoardGame_Classes.h"


template <typename T>
class numerical_Board : public Board<T> {
public:
    numerical_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class numerical_Player : public Player<T> {
    vector<int> available_numbers;
    T selected_number;
public:
    numerical_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class numerical_Random_Player : public RandomPlayer<T> {
    vector<int> available_numbers;
    T selected_number; 
public:
    numerical_Random_Player(T symbol);
    void getmove(int& x, int& y);
};
bool flags = true;
//--------------------------------------- IMPLEMENTATION

#include <bits/stdc++.h>

using namespace std;

// Constructor for numerical_Board
template <typename T>
numerical_Board<T>::numerical_Board() {
    this->rows = this->columns = 3;
    this->board = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;  // Initialize board with 0
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool numerical_Board<T>::update_board(int x, int y, T selected_number) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || selected_number == 0)) {
        if (selected_number == 0) {
            this->n_moves--;
            this->board[x][y] = 0;  // Reset the board position
        } else {
            this->n_moves++;
            this->board[x][y] = static_cast<int>(selected_number);  // Convert to int for board
        }
        return true;
    }
    flags = false;
    return false;
}

// Display the board and the pieces on it
template <typename T>
void numerical_Board<T>::display_board() {
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
        cout << "\n----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool numerical_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if (((this->board[i][0] + this->board[i][1] + this->board[i][2]) == 15 && this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0) ||
            ((this->board[0][i] + this->board[1][i] + this->board[2][i]) == 15 && this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if (((this->board[0][0] + this->board[1][1] + this->board[2][2]) == 15 && this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0) ||
        ((this->board[0][2] + this->board[1][1] + this->board[2][0]) == 15 && this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0)) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool numerical_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool numerical_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for numerical_Player
template <typename T>
numerical_Player<T>::numerical_Player(string name, T symbol) : Player<T>(name, symbol), selected_number(0) {
    if (symbol == 'X') {
        available_numbers = {1, 3, 5, 7, 9};  // Odd numbers for 'X'
    } else if (symbol == 'O') {
        available_numbers = {2, 4, 6, 8};  // Even numbers for 'O'
    }
}

template <typename T>
void numerical_Player<T>::getmove(int& x, int& y) {
    if(!flags){
        available_numbers.push_back(this->symbol);
        sort(available_numbers.begin(), available_numbers.end());
        flags = true;
    }
    cout << "\nAvailable numbers: ";
    for (int i = 0; i < available_numbers.size(); i++) {
        cout << available_numbers[i] << " ";  // Show available numbers
    }
    cout << "\nEnter your move (x y) and select a number: ";
    while (true) {
            cin >> x >> y >> selected_number;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }

    // Validate the selected number
    auto it = find(available_numbers.begin(), available_numbers.end(), selected_number);
    if (it != available_numbers.end() && x >=0 && x <= 2 && y >= 0 && y <= 2) {
        available_numbers.erase(it);  // Remove used number from available options
    } else {
        cout << "Invalid number. Try again.\n";
        getmove(x, y);  // Retry move
    }
    this->symbol = selected_number;
}


// Constructor for numerical_Random_Player
template <typename T>
numerical_Random_Player<T>::numerical_Random_Player(T symbol) : RandomPlayer<T>(symbol), selected_number(0) {
    if (symbol == 'X') {
        available_numbers = {1, 3, 5, 7, 9};  // Odd numbers for 'X'
    } else if (symbol == 'O') {
        available_numbers = {2, 4, 6, 8};  // Even numbers for 'O'
    }
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
}

template <typename T>
void numerical_Random_Player<T>::getmove(int& x, int& y) {
    if(!flags){
        available_numbers.push_back(this->symbol);
        sort(available_numbers.begin(), available_numbers.end());
        flags = true;
    }
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;

    int index = rand() % available_numbers.size();
    selected_number = available_numbers[index];
    available_numbers.erase(available_numbers.begin() + index);  // Remove selected number
    
    this->symbol = selected_number;
}


#endif //NUMERICAL_H
