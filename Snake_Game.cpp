#include <bits/stdc++.h>
#include <conio.h>       // for kbhit(), getch()
#include <windows.h>     // for console control

using namespace std;

#define MAX_LENGTH 1000

// Direction constants
const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

int consoleWidth, consoleHeight;

void initScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

struct Point {
    int xCoord;
    int yCoord;

    Point() {}

    Point(int x, int y) {
        xCoord = x;
        yCoord = y;
    }
};

class Snake {
    int length;
    char direction;

public:
    Point body[MAX_LENGTH];

    Snake(int x, int y) {
        length = 1;
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    int getLength() {
        return length;
    }

    void changeDirection(char newDir) {
        if ((newDir == DIR_UP && direction != DIR_DOWN) ||
            (newDir == DIR_DOWN && direction != DIR_UP) ||
            (newDir == DIR_LEFT && direction != DIR_RIGHT) ||
            (newDir == DIR_RIGHT && direction != DIR_LEFT)) {
            direction = newDir;
        }
    }

    bool move(Point food) {
        for (int i = length - 1; i > 0; i--) {
            body[i] = body[i - 1];
        }

        switch (direction) {
            case DIR_UP:
                body[0].yCoord -= 1;
                break;
            case DIR_DOWN:
                body[0].yCoord += 1;
                break;
            case DIR_RIGHT:
                body[0].xCoord += 1;
                break;
            case DIR_LEFT:
                body[0].xCoord -= 1;
                break;
        }

        // Check self-collision
        for (int i = 1; i < length; i++) {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord) {
                return false;
            }
        }

        // Check food collision
        if (body[0].xCoord == food.xCoord && body[0].yCoord == food.yCoord) {
            body[length] = body[length - 1];
            length++;
        }

        return true;
    }
};

class Board {
    Snake* snake;
    Point food;
    int score;

    const char SNAKE_BODY = 'O';
    const char FOOD = 'o';

public:
    Board() {
        spawnFood();
        snake = new Snake(10, 10);
        score = 0;
    }

    ~Board() {
        delete snake;
    }

    int getScore() {
        return score;
    }

    void gotoxy(int x, int y) {
        COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void spawnFood() {
        int x = rand() % consoleWidth;
        int y = rand() % consoleHeight;
        food = Point(x, y);
    }

    void displayCurrentScore() {
        gotoxy(consoleWidth / 2, 0);
        cout << "Current Score: " << score;
    }

    void draw() {
        system("cls");
        for (int i = 0; i < snake->getLength(); i++) {
            gotoxy(snake->body[i].xCoord, snake->body[i].yCoord);
            cout << SNAKE_BODY;
        }

        gotoxy(food.xCoord, food.yCoord);
        cout << FOOD;

        displayCurrentScore();
    }

    bool update() {
        bool alive = snake->move(food);
        if (!alive) return false;

        if (snake->body[0].xCoord == food.xCoord && snake->body[0].yCoord == food.yCoord) {
            score++;
            spawnFood();
        }

        return true;
    }

    void getInput() {
        if (kbhit()) {
            int key = getch();
            switch (key) {
                case 'w':
                case 'W':
                    snake->changeDirection(DIR_UP);
                    break;
                case 'a':
                case 'A':
                    snake->changeDirection(DIR_LEFT);
                    break;
                case 's':
                case 'S':
                    snake->changeDirection(DIR_DOWN);
                    break;
                case 'd':
                case 'D':
                    snake->changeDirection(DIR_RIGHT);
                    break;
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    initScreen();

    Board* gameBoard = new Board();

    while (gameBoard->update()) {
        gameBoard->getInput();
        gameBoard->draw();
        Sleep(100); // Delay for game speed
    }

    cout << "\nGame Over!\n";
    cout << "Final Score: " << gameBoard->getScore() << endl;

    delete gameBoard;
    return 0;
}
