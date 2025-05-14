# Board-Games
C++ gaming framework for board games like Tic-Tac-Toe and Connect 4. Uses OOP with abstract templates, inheritance, and polymorphism for modularity. Supports human players and game management.
Gaming Framework in C++

# Overview

- This C++ project implements a modular gaming framework for various board games (e.g., Tic-Tac-Toe, Connect 4, Numerical Board) using object-oriented programming. It leverages abstract template classes, inheritance, and polymorphism to ensure extensibility and clarity.
- The framework supports different board types, human players, and game management.

# Features

- Abstract Classes: Board and Player templates define core functionality for game boards and players.
- Derived Classes: Specific boards (e.g., 3x3 Tic-Tac-Toe, Connect 4) and human players.
- Game Management: GameManager orchestrates gameplay, handling moves, win/draw checks, and board updates.
- Modularity: Template-based design allows reusability across game types and symbols.

# Usage

- Compile and run the program using a C++ compiler (e.g., g++).
- Select a game mode (e.g., 3x3 Tic-Tac-Toe, Connect 4) from the menu.
- Follow prompts to:
  - Input moves (e.g., row/column for Tic-Tac-Toe, column for Connect 4).
  - View the updated board after each move.


  - Continue until a win, draw, or game exit.

  - Example (Tic-Tac-Toe):
    ``` bash
    Select game: 3x3 Tic-Tac-Toe
    Player 1 (X) move (row, col): 1 1
  
        X |   |  
       ---+---+---
          |   |  
       ---+---+---
          |   |
   
    Player 2 (O) move (row, col): 2 2
    ...
    Game over: Player 1 wins!
    ```

# Limitations

- Hardcoded win conditions in some games reduce maintainability.
- Draw detection incomplete in some implementations (e.g., 4x4 Tic-Tac-Toe).
- Console-based; no graphical interface.

# License
This project is licensed under the MIT License. See the LICENSE file for details.

# Authors

- Mariam Hesham (20230400) - [mariam0905]
- Fahd Deya El-din (20230287)
- Habiba Hany (20230120)
- Computer Science Students at Cairo University

# Acknowledgments

- Developed for CS213 (Object-Oriented Programming), Cairo University.
- Thanks to Prof. Mohamed El-Ramly for guidance.

