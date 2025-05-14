#ifndef SUS_H
#define SUS_H
#include <vector>
#include <fstream>
#include <unordered_set>
#include <set>
#include"BoardGame_Classes.h"

using namespace std;



template <typename T>
class SU_Board:public Board<T> {
public:
    SU_Board ();
    void counter(int& c, int& d);
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();


};

template <typename T>
class SU_Player : public Player<T> {
public:
    SU_Player (string name, T symbol);
    void getmove(int& x, int& y) ;



};

template <typename T>
class SU_Random_Player : public RandomPlayer<T>{
public:
    SU_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>

using namespace std;

template <typename T>
SU_Board<T>::SU_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

int a , b;
int countS = 0;
int countU = 0;
bool diagonal1 = false;
bool diagonal2 = false;

////////////////////////////////////
template <typename T>
bool SU_Board<T>::update_board(int x, int y, T mark) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 0) {
        return false;
    }
    a = x;
    b = y;
    this->n_moves++;
    this->board[x][y] =toupper(static_cast<char>(mark));
    return true;
}

// Display the board and the pieces on it
template <typename T>
void SU_Board<T>::display_board() {
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
    counter(countS, countU);
    cout << endl;
    cout << "The number of wins of S: " << countS << endl;
    cout << "The number of wins of U: " << countU << endl;
}

template <typename T>
void SU_Board<T>::counter(int& c, int& d) {

    if (this->board[a][0] == this->board[a][2] && this->board[a][0] == 'S' && this->board[a][1] == 'U')
    {
        if (this->n_moves % 2 != 0) 
        {
            countS++;
        }
            
        else
        {
            countU++;
        }
    }
    if (this->board[0][b] == this->board[2][b] && this->board[0][b] == 'S' && this->board[1][b] == 'U')
    {
        if (this->n_moves % 2 != 0)
        {
            countS++;
        } 
        else 
        {
            countU++;
        }
    }

    if((a == 0 && b == 0) || (a == 1 && b == 1) || (a == 0 && b == 2) || (a == 2 && b == 0) || (a == 2 && b == 2))
    {
        if (this->board[0][0] == this->board[2][2] && this->board[0][0] == 'S' && this->board[1][1] == 'U')
        {
            if(!diagonal1)
            {
                diagonal1 = true;
                if (this->n_moves % 2 != 0)
                {
                    countS++;
                }
                else
                {
                    countU++;
                } 
            }

            }
            if (this->board[0][2] == this->board[2][0] && this->board[0][2] == 'S' && this->board[1][1] == 'U')
            {
                if(!diagonal2)
                {
                    diagonal2 = true;
                    if (this->n_moves % 2 != 0)
                    {
                         countS++;
                    }
                    else
                    {
                        countU++;
                    } 
                }
            }
    }
}

template <typename T>
bool SU_Board<T>::is_win() {
    if (this->n_moves < 9) return false;
    counter(countS, countU);
    if (countS > countU)
    {
        return true;
    }
    else if (countU > countS) 
    {
        return true;
    }
    return false;
}



template <typename T>
bool SU_Board<T>::is_draw() {
    if (this->n_moves < 9)
        return false;
    return (countS == countU);
}

template <typename T>
bool SU_Board<T>::game_is_over() {
    if (this->n_moves < 9)
        return false;
    
    if (is_win() || is_draw())
    {
        diagonal1 = false;
        diagonal2 = false;
        countS = 0;
        countU = 0;
        return true;
    }
    return false;
}

//--------------------------------------

template <typename T>
SU_Player<T>::SU_Player(string name, T mark ) : Player<T>(name, mark) {}



template <typename T>
void SU_Player<T>::getmove(int& x, int& y) {
    x=y=3;
    cout << "\nenter your move x and y (0 to 2) separated by spaces: ";
    while (true) {
        cin >> x >>y;
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
SU_Random_Player<T>::SU_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void SU_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;


}



#endif // SUS_H
