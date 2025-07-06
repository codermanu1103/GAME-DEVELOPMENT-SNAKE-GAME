# GAME-DEVELOPMENT-SNAKE-GAME

COMPANY NAME - CODTECH IT SOLUTIONS

NAME - Manthan Gupta

INTERN ID - CT06DN1592

DOMAIN NAME - C++ Programming 

DURATION - 6 WEEKS(May 21st to July 6th 2025)

MENTOR - NEELA SANTHOSH KUMAR

Description:

🐍 Overview
This C++ program is a console-based snake game, built using:
ASCII graphics
Windows-specific headers: <windows.h>, <conio.h>
Keyboard input handling with getch() and kbhit()
Sleep() for game speed control
Console cursor movement via gotoxy() for game rendering

The game features:
A snake that moves continuously on screen.
Player-controlled direction via WASD keys.
Food that appears randomly on the screen.
Score incrementing when food is eaten.
Snake growth and game-over detection when the snake collides with itself.

📐 Global Variables and Constants
consoleWidth, consoleHeight: Store terminal dimensions.
MAX_LENGTH: Maximum length of the snake.
DIR_UP, DIR_DOWN, etc.: Constants for movement directions.

📺 Function: initScreen()
Uses GetConsoleScreenBufferInfo() to fetch the console size (width and height).
These dimensions are used to randomly place food and check screen boundaries.

🧩 Struct: Point
Represents a coordinate (x, y) on the screen.
Used for both food and each segment of the snake's body.

🐍 Class: Snake
Manages the snake’s body and behavior.

🔑 Key Members:
body[MAX_LENGTH]: Array of Point storing body segments.
length: Current length of the snake.
direction: Current direction of movement.

🔧 Methods:
changeDirection(char): Changes direction only if it's not directly opposite.
move(Point food):
Shifts all segments to follow the head.
Updates head based on direction.
Checks for self-collision.
Increases length if food is eaten.
Returns false if the snake dies.

🎮 Class: Board
Controls the game board, drawing, score, food placement, and input.

🔑 Key Members:
Snake* snake: Pointer to the Snake object.
Point food: Current food location.
int score: Tracks the score.
char SNAKE_BODY, FOOD: Symbols to draw snake and food.

🔧 Important Methods:
spawnFood(): Generates food at random console coordinates.
gotoxy(int x, int y): Moves the console cursor using SetConsoleCursorPosition().
displayCurrentScore(): Prints score at the top-middle of the screen.
draw(): Clears screen, draws the snake, food, and score.
update(): Moves the snake and checks for food collision and self-collision. Respawns food and increases score if food is eaten.
getInput(): Detects if WASD keys are pressed and updates direction accordingly using kbhit() and getch().

🏁 Function: main()
Seeds random number generator for food positioning.
Initializes console screen dimensions.
Creates a new Board object.

Game loop:
Calls update() to move snake and check game state.
Handles keyboard input.
Redraws screen every 100 milliseconds using Sleep(100).
On game over, prints “Game Over” and the final score.

✅ Features
Real-time input handling: With kbhit() and getch(), it reads keypresses without pausing the game.
Collision detection: The game ends if the snake runs into itself.
Dynamic snake growth: The snake grows every time it eats food.
Live score display: Score is updated in real-time during gameplay.
Random food spawn: Food appears at new random locations each time it is eaten.

📚 Conclusion
This Snake game is a simple yet educational example of:
Real-time programming
Basic game loop architecture
Console manipulation

Output:
<img width="1044" height="420" alt="Image" src="https://github.com/user-attachments/assets/1f021026-3bc0-423c-b804-dec7f151cd79" />
