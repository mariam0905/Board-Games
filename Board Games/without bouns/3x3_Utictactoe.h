#ifndef _3X3UTICTACTOE_H
#define _3X3TICTACTOE_H
#include "BoardGame_Classes.h"
#include "3x3X_O.h"
char new_symbol;

template <typename T>
class Utictactoe_Board:public Board<T> 
{
    public:
        Utictactoe_Board ();
        bool update_board (int x, int y, T symbol);
        void display_board () ;
        bool is_win() ;
        bool is_draw();
        bool game_is_over();
};

template <typename T>
class myGameManager : public GameManager<T>
{
    private:
        Board<T>* myboardPtr;
    public:
        myGameManager(Board<T>* , Player<T>* playerPtr[2]);
        void myrun();
};


//--------------------------------------- IMPLEMENTATION


#include <iostream>
#include <iomanip>
#include <cctype> 
#include <limits>
using namespace std;

template <typename T>
myGameManager<T>::myGameManager(Board<T>* bPtr, Player<T>* playerPtr[2]) : GameManager<T>(bPtr, playerPtr)
{
    myboardPtr = bPtr;
}
template<typename T>
void myGameManager<T>::myrun()
{
    while (!myboardPtr->game_is_over()) 
    {
            myboardPtr->update_board(1, 1 , 'o'); 
            cout << endl;
            cout << "The Ultimate board result : " << endl;
            myboardPtr->display_board();
            if (myboardPtr->is_win()) 
            {
                cout << "Team playing with the symbol : " << new_symbol << " wins\n";
                return;
            }
            if (myboardPtr->is_draw()) 
            {
                cout << "Draw! in the Ultimate board\n";
                return;
            }
    }
}
// Constructor for Utictactoe_Board
template <typename T>
Utictactoe_Board<T>::Utictactoe_Board() 
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
int answer;
template <typename T>
bool Utictactoe_Board<T>::update_board(int x, int y, T symbol) 
{
    cout << endl;
    cout << "Please enter the number of the sub-board to play in : \n\n" ;
    int arr[3][3];
    int k = 1;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ;j < 3 ; j++)
        {
            arr[i][j] = k;
            k++;
            cout << arr[i][j] << "     ";
        }
        cout << "\n\n";
    }
    while(true)
    {
        cin >> answer;
        if(cin.fail())  
        {   
            cin.clear();   
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   
            cout << "Invalid input. Please enter a valid number.\n";   
        }   
        else if(answer <= 0 || answer > 9)  
        {   
            cout << "Number must be between 1 and 9. Please try again.\n";   
        } 
        else if((answer == 1 && this->board[0][0] != 0) || (answer == 2 && this->board[0][1] != 0) || (answer == 3 && this->board[0][2] != 0) || (answer == 4 && this->board[1][0] != 0) || (answer == 5 && this->board[1][1] != 0) || (answer == 6 && this->board[1][2] != 0) || (answer == 7 && this->board[2][0] != 0) || (answer == 8 && this->board[2][1] != 0) || (answer == 9 && this->board[2][2] != 0))  
        {
            cout << "The sub-board you chosen has been chosen before, so please choose another sub-board and also make sure you choose between 1 and 9 " << endl;
        }
        else  
            break;   
    }
    Player<char>* players[2];
    X_O_Board<char>* B = new X_O_Board<char>();
    string p1, p2;
    char choice;
    cout << endl;
    cout << "Choose wether you want the first player to be a human player or a random computer player : \na)Human player \nb)random computer player" << endl;
    cin >> choice;
    choice = tolower(choice);
    while(choice != 'a' && choice != 'b')
    {
        cout << endl;
        cout << "Please enter a valid option , wether a or b" << endl;
        cin >> choice;
    }
    if(choice == 'a')
    {
        cout << endl;
        cout << "Enter the first player name (without spaces) : " << endl;
        cin >> p1;
        players[0] = new X_O_Player<char>(p1, 'X');
    }
    else
        players[0] = new X_O_Random_Player<char>('X');
    cout << endl;
    cout << "Choose wether you want the second player to be a human player or a random computer player : \na)Human player \nb)random computer player" << endl;
    cin >> choice;
    choice = tolower(choice);
    while(choice != 'a' && choice != 'b')
    {
        cout << endl;
        cout << "Please enter a valid option , wether a or b" << endl;
        cin >> choice;
    }
    if(choice == 'a')
    {
        cout << endl;
        cout << "Enter the second player name (without spaces) : " << endl;
        cin >> p2;
        players[1] = new X_O_Player<char>(p2, 'O');
    }
    else
        players[1] = new X_O_Random_Player<char>('O');
    // run the game
    int a, b;
    cout << endl;
    cout << "Welcome to the sub-board with the number : " << answer << " you chosen " << endl;
    cout << "The chosen sub-board with the number " << answer << " result : " << endl;
    B->display_board();
    while (!B->game_is_over()) 
    {
        for (int i : {0, 1}) 
        {
            players[i]->getmove(a, b);
            while (!B->update_board(a, b, players[i]->getsymbol())) 
            {
                players[i]->getmove(a, b);
            }
            cout << "The chosen sub-board with the number " << answer << " result : " << endl;
            B->display_board();
            if (B->is_win()) 
            {
                cout << players[i]->getname() << " wins\n";
                new_symbol = players[i]->getsymbol();
                break;
            }
            if (B->is_draw()) 
            {
                cout << "Draw!\n";
                cout << "You should play again to fill the sub-board of number " << answer << " you chosen " << endl;
                new_symbol = 0;
                this->n_moves--;
                break;
            }
        }
    }
    if (this->board[0][0] == 0 && answer == 1)
    {
        this->board[0][0] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[0][1] == 0 && answer == 2)
    {
        this->board[0][1] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[0][2] == 0 && answer == 3)
    {
        this->board[0][2] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[1][0] == 0 && answer == 4)
    {
        this->board[1][0] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[1][1] == 0 && answer == 5)
    {
        this->board[1][1] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[1][2] == 0 && answer == 6)
    {
        this->board[1][2] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[2][0] == 0 && answer == 7)
    {
        this->board[2][0] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[2][1] == 0 && answer == 8)
    {
        this->board[2][1] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    else if (this->board[2][2] == 0 && answer == 9)
    {
        this->board[2][2] = toupper(new_symbol);
        this->n_moves++;
        return true;
    }
    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
     {
        delete players[i];
    }
    return false;
   
}
// Display the board and the pieces on it
template <typename T>
void Utictactoe_Board<T>::display_board()
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
                cout << setw(4) << "  "  << setw(4) << " |";
            }
        }
        cout << "\n--------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool Utictactoe_Board<T>::is_win() 
{
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) 
    {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) 
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) 
    {
        return true;
    }
    return false;
}
// Return true if 9 moves are done and no winner
template <typename T>
bool Utictactoe_Board<T>::is_draw() 
{
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Utictactoe_Board<T>::game_is_over() 
{
    return (is_win() || is_draw());
}

//--------------------------------------



#endif //_3X3UTICTACTOE_H