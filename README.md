## Quoridor Game
This is a C++ console-based game project where two players (P and R) place walls and move across a grid. The objective is to reach the opposite side of the board first while strategically placing walls to block the opponent.

## How to Play

1. **Start Game**: 
   - Choose option `1` to start the game.
   - The board will display with player positions and available moves.

2. **Game Turns**:
   - Each player takes turns to either **Add Wall** or **Move**.
   - Players can choose between placing a horizontal or vertical wall, or moving up, down, left, or right.

3. **Objective**:
   - The player who reaches the opponent's starting row first wins.

## Game Controls

- **Menu Options**: 
  - `1` to Start the Game.
  - `2` to Exit.

- **Player Actions**:
  - **Add Wall**: 
    - Choose between Horizontal (1) or Vertical (2) placement.
  - **Move**: 
    - Choose the direction: Up (1), Down (2), Left (3), Right (4).

## Compilation and Execution

1. To compile the code, use the following command in your terminal:
   ```bash
   g++ -o GameBoard Project.cpp
