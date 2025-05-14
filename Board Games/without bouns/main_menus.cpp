#include <iostream>
#include "BoardGame_Classes.h"
#include "PyramidXOTicTacToe.h"
#include "3x3X_O.h"
#include "Connect4.h"
#include "5x5TicTacToe.h"
#include "WordTicTacToe1.h"
#include "numerical.h"
#include "3x3_toetactic.h"
#include "4x4X_O.h"
#include "3x3_Utictactoe.h"
#include "SUS.h"


using namespace std;

int main(){


int choice1;
cout << "Welcome to the games hub program.\n";
do
{
    
    
    cout << "\n1)Pyramic Tic-Tac-Toe.\n";
    cout << "2)Four-in-a-row.\n";
    cout << "3)5x5 Tic Tac Toe.\n";
    cout << "4)Word Tic Tac Toe.\n";
    cout << "5)Numerical Tic-Tac-Toe.\n";
    cout << "6)Misere Tic-Tac-Toe.\n";
    cout << "7)4x4 Tic-Tac-Toe.\n";
    cout << "8)Ultimate Tic-Tac-Toe.\n";
    cout << "9)SUS.\n";
    cout << "10)Exit\n";
    cout << "Please choose which game do you want to play: ";
    while (true) {
        cin >> choice1;
        if (cin.fail()){
            cout << "Invalid input! Please enter a number between 1 and 8.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(choice1 < 1 || choice1 > 10){
            cout << "Invalid choice, please try again.\n";
        }
        else{
            break;
        }
    }

    if(choice1 == 1){
        int choice2;
        Player<char>* players[2];
        PyramidXOTicTacToeBoard<char>* B = new PyramidXOTicTacToeBoard<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new PyramidXOTicTacToePlayer<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new PyramidXOTicTacToeRandomPlayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new PyramidXOTicTacToePlayer<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new PyramidXOTicTacToeRandomPlayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> Pyramid_game(B, players);
        Pyramid_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }

// ------------------------------------------------------------------------------------------------------------------------------------

    else if(choice1 == 2){
        int choice2;
        Player<char>* players[2];
        Connect4_Board<char>* B = new Connect4_Board<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new Connect4_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new Connect4_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new Connect4_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Connect4_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> connect4_game(B, players);
        connect4_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }

// ------------------------------------------------------------------------------------------------------------------------------

    else if(choice1 == 3){
        int choice2;
        Player<char>* players[2];
        TicTacToe_Board<char>* B = new TicTacToe_Board<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new TicTacToe_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new TicTacToe_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new TicTacToe_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new TicTacToe_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> tictactoe_game(B, players);
        tictactoe_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

    }


// --------------------------------------------------------------------------------------------------------------------------------------
    
    else if(choice1 == 4){
        int choice2;
        Player<char>* players[2];
        WordTicTacToeBoard<char>* B = new WordTicTacToeBoard<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new WordTicTacToePlayer<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new WordTicTacToeRandomPlayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new WordTicTacToePlayer<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new WordTicTacToeRandomPlayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> word_game(B, players);
        word_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }

// --------------------------------------------------------------------------------------------------------------------------------------

    else if(choice1 == 5){
        int choice2;
        Player<int>* players[2];
        numerical_Board<int>* B = new numerical_Board<int>();
        string playerXName, player2Name;
        cout << "Choose Player Odd numbers type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1/2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player Odd numbers name: ";
            cin >> playerXName;
            players[0] = new numerical_Player<int>(playerXName, 'X');
            break;
        case 2:
            players[0] = new numerical_Random_Player<int>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1/2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new numerical_Player<int>(player2Name, 'O');
            break;
        case 2:
            players[1] = new numerical_Random_Player<int>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<int> numerical_game(B, players);
        numerical_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

    }


// ---------------------------------------------------------------------------------------------------------------------------------------
    else if(choice1 == 6){
        int choice2;
        Player<char>* players[2];
        toetactic_Board<char>* B = new toetactic_Board<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new toetactic_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new toetactic_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new toetactic_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new toetactic_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> toetactic_game(B, players);
        toetactic_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }


// --------------------------------------------------------------------------------------------------------------------------------------
    
    
    else if(choice1 == 7){
        int choice2;
        Player<char>* players[2];
        X4_O4_Board<char>* B = new X4_O4_Board<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new X4_O4_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new X4_O4_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new X4_O4_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new X4_O4_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> X4_O4_game(B, players);
        X4_O4_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

    }


// ----------------------------------------------------------------------------------------------------------------------------------------
    else if(choice1 == 8){
        cout << "Welcome to the 3x3 Ultimate TicTacToe game !" << endl;
        Utictactoe_Board<char>* bptr = new Utictactoe_Board<char>();
        Player<char>* players[2];
        players[0] = new X_O_Player<char>("mariam", 'X');
        players[1] = new X_O_Random_Player<char>('O');
        myGameManager<char> utictactoe_game(bptr , players);
        utictactoe_game.myrun();
    }

// ----------------------------------------------------------------------------------------------------------------------------------------


else if(choice1 == 9){
        int choice2;
        Player<char>* players[2];
        SU_Board<char>* B = new SU_Board<char>();
        string playerXName, player2Name;
        cout << "Choose Player X type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice2;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice2 < 1 || choice2 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice2) {
        case 1:
            cout << "Enter Player X name: ";
            cin >> playerXName;
            players[0] = new SU_Player<char>(playerXName, 'S');
            break;
        case 2:
            players[0] = new SU_Random_Player<char>('S');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        int choice3;
        cout << "Choose Player O type:\n";
        cout << "1) Human\n";
        cout << "2) Random Computer\n";
        while (true) {
            cin >> choice3;
            if (cin.fail()){
                cout << "Invalid input! Please enter a number (1 or 2).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(choice3 < 1 || choice3 > 2){
                cout << "Invalid choice, please try again.\n";
            }
            else{
                break;
            }
        }
        switch(choice3) {
        case 1:
            cout << "Enter Player O name: ";
            cin >> player2Name;
            players[1] = new SU_Player<char>(player2Name, 'U');
            break;
        case 2:
            players[1] = new SU_Random_Player<char>('U');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
        }
        GameManager<char> SU_game(B, players);
        SU_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

    }
} while (choice1 != 10);

cout << "\nSee you soon .. :)";
}