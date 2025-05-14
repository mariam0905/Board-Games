#ifndef _3X3X_WORD_TICTACTOE_H
#define _3X3X_WORD_TICTACTOE_H

#include "BoardGame_Classes.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class WordTicTacToeBoard : public Board<T> {
public:
    WordTicTacToeBoard();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

private:
    bool check_word(const string& word);
    set<string> dictionary;
};

template <typename T>
class WordTicTacToePlayer : public Player<T> {
public:
    WordTicTacToePlayer(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class WordTicTacToeRandomPlayer : public RandomPlayer<T> {
public:
    WordTicTacToeRandomPlayer(T symbol);
    void getmove(int& x, int& y);
};

//---------------------------------------IMPLEMENTATION

set<string> load_dictionary() {
    set<string> dictionary;
    ifstream file("dic.txt");
    string word;
    while (file >> word) {
        dictionary.insert(word);
    }
    file.close();
    
    return dictionary;
}

template <typename T>
WordTicTacToeBoard<T>::WordTicTacToeBoard() {
    this->rows = this->columns = 3;
    this->n_moves = 0;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    dictionary = load_dictionary();
}

template <typename T>
bool WordTicTacToeBoard<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void WordTicTacToeBoard<T>::display_board() {
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
bool WordTicTacToeBoard<T>::check_word(const string& word) {
    return dictionary.count(word);
}

template <typename T>
bool WordTicTacToeBoard<T>::is_win() {
    for (int i = 0; i < this->rows; ++i) {
        string R, C;
        for (int j = 0; j < this->columns; ++j) {
            R += this->board[i][j];
            C += this->board[j][i];
        }
        if (check_word(R) || check_word(C)) return true;
    }
    string D1, D2;
    for (int i = 0; i < this->rows; ++i) {
        D1 += this->board[i][i];
        D2 += this->board[i][this->columns - 1 - i];
    }
    return check_word(D1) || check_word(D2);
}

template <typename T>
bool WordTicTacToeBoard<T>::is_draw() {
    return this->n_moves == 9 && !is_win();
}

template <typename T>
bool WordTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
WordTicTacToePlayer<T>::WordTicTacToePlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void WordTicTacToePlayer<T>::getmove(int& x, int& y) {
    cout << "\nEnter your move (x y): ";
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
    cout << "Enter a letter between (A-Z): ";
    string z;
    cin >> z;
    z[0] = toupper(z[0]);
    while (z[0] < 'A' || z[0] > 'Z' || z.size() != 1) {
        cout << "Please enter a valid input: ";
        cin >> z;
        z[0] = toupper(z[0]);
    }
    this->symbol = z[0];
}

template <typename T>
WordTicTacToeRandomPlayer<T>::WordTicTacToeRandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    srand(static_cast<unsigned int>(time(0)));
    this->name = "Random Word Player";
}

template <typename T>
void WordTicTacToeRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 3;
    int randomNumber = rand() % 26 + 97;
    static_cast<char>(randomNumber);
    this->symbol = randomNumber;
}

#endif //_3X3X_WORD_TICTACTOE_H
