#include <Windows.h>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <thread>
#include <vector>
#include <variant>

using namespace std;

//void rand_set_picker(vector<int> c);
int random_picker(int a, int b);

void gotopos(int x, int y);
void check_direction(void);
void draw_player(int x, int y);
void draw_borders();
//void spawn_apple();
void add_first_apple();
void store_snake_pos();
bool check_collision(void);
void display_game_over(void);
void refresh_game(void);

const int SPEED = 10;
const int HEIGHT = 25;
const int WIDTH = 25;
const char SNAKE = 'S';

vector<vector<int>> snake = {};

int player_pos_x = 0;
int player_pos_y = 0;
int end_pos_x = player_pos_x;
int end_pos_y = player_pos_y;
int apple_pos_x;
int apple_pos_y;
int score = 0;

int main(void) {
    bool play = true;
    while (play) {
        draw_borders();
        add_first_apple();
        check_direction();
        char ask;
        do {
            gotopos(0, 3 + HEIGHT);
            cout << "Play another game(y/n)?: ";
            ask = _getch();
            if (ask == 'y') {
                refresh_game();
                system("cls");
            }
            else if (ask == 'n') {
                play = false;
                break;
            }
        } while (ask != 'y' && ask != 'n');
    }
    return 0;
}

void draw_borders(void) {
    cout << '+';
    for (int i = 0; i < WIDTH; i++) {
        cout << "--";
    }
    cout << "---+" << "Score: " << score << endl;
    for (int i = 0; i < HEIGHT + 1; i++) {
        cout << '|';
        for (int j = 0; j < WIDTH + 1; j++) {
            cout << "  ";
        }
        cout << " |" << endl;
    }
    cout << '+';
    for (int i = 0; i < WIDTH; i++) {
        cout << "--";
    }
    cout << "---+ " << endl;
}

void refresh_game(void) {
    player_pos_x = 0;
    player_pos_y = 0;
    end_pos_x = player_pos_x;
    end_pos_y = player_pos_y;
    score = 0;
    snake = {};
}

void gotopos(int x, int y) {
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);

}

void draw_player(int x, int y) {
	gotopos(2 + x*2, 1 + y);
	cout << SNAKE;
	return;
}

//================================APPLE SPAWNING==========================================
void remove_end();
void add_first_apple(void) {
    apple_pos_x = random_picker(0, WIDTH);
    apple_pos_y = random_picker(0, HEIGHT);
    gotopos(2 + apple_pos_x * 2, 1 + apple_pos_y);
    cout << "a";
}
void add_apple(void) {
    while (true) {
        
        int pos_x = random_picker(0, WIDTH);
        int pos_y = random_picker(0, HEIGHT);
        bool in_tail = false;
        for (int i = 0; i < snake.size(); i++) {
            if (pos_x == snake[i][0] && pos_y == snake[i][1]) {
                in_tail = true;
                break;
            }
        }
        if (in_tail || (pos_x == player_pos_x && pos_y == player_pos_y)) {
            continue;
        }
        else {
            apple_pos_x = pos_x;
            apple_pos_y = pos_y;
            break;
        }
    }
    gotopos(2 + apple_pos_x * 2, 1 + apple_pos_y); // go to a random position
    cout << "a";
    return;
}

void remove_apple(int x, int y) {
    gotopos(2 + x * 2, 1 + y);
    apple_pos_x = 0; apple_pos_y = 0;
    cout << SNAKE;
    return;
}
void spawn_apple(char direc) {   
    remove_apple(player_pos_x, player_pos_y);
    add_apple();
    score++;
    gotopos(62, 0);
    cout << score;
    return;
}

//===============================CHECK DIRECTION==========================================
void move_up(void);
void move_down(void);
void move_left(void);
void move_right(void);
void remove_end();

void check_direction(void) {
    char direction = 'd';
    char current_direction = direction;
    while (true) {
        if (_kbhit()) {
            direction = _getch();
            if (direction == 'w' && current_direction != 's') {
                current_direction = direction;
                move_up();
            }
            else if (direction == 'w' && current_direction == 's') {
                move_down();
            }

            if (direction == 'a' && current_direction != 'd') {
                current_direction = direction;
                move_left();
            }
            else if (direction == 'a' && current_direction == 'd') {
                move_right();
            }

            if (direction == 's' && current_direction != 'w') {
                current_direction = direction;
                move_down();
            }
            else if (direction == 's' && current_direction == 'w') {
                move_up();
            }
            if (direction == 'd' && current_direction != 'a') {
                current_direction = direction;
                move_right();
            }
            else if (direction == 'd' && current_direction == 'a') {
                move_left();
            }
        }
        else {
            direction = current_direction;
            if (direction == 'w') {
                move_up();
            }
            else if (direction == 'a') {
                move_left();
            }
            else if (direction == 's') {
                move_down();
            }
            else if (direction == 'd') {
                move_right();
            }

        }
        if (check_collision()) {
            display_game_over();
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000 / SPEED));
        store_snake_pos();
        if (player_pos_x == apple_pos_x && player_pos_y == apple_pos_y) {
            spawn_apple(current_direction);
        }
        else {
            remove_end();
        }
        
    }
}

void move_up(void) {
    if (player_pos_y >= 0) {
        player_pos_y--;
        draw_player(player_pos_x, player_pos_y);
    }
    return;
}

void move_down(void) {
    if (player_pos_y <= HEIGHT) {
        player_pos_y++;
        draw_player(player_pos_x, player_pos_y);
    }
    return;
}

void move_left(void) {
    if (player_pos_x >= 0) {
        player_pos_x--;
        draw_player(player_pos_x, player_pos_y);
    }
    return;
}

void move_right(void) {
    if (player_pos_x <= WIDTH) {
        player_pos_x++;
        draw_player(player_pos_x, player_pos_y);
    }
    return;
}

int cashex, cashey;
void remove_end() {
    gotopos(2 + (snake[0][0]) * 2, 1 + snake[0][1]);
    cashex = snake[0][0];
    cashey = snake[0][1];
    snake.erase(snake.begin());
    cout << " ";
    return;
}

void store_snake_pos(void) {
    vector<int> body_pos= {};
    body_pos.push_back(player_pos_x);
    body_pos.push_back(player_pos_y);
    snake.push_back(body_pos);
    return;
}

//===========================================CHECK COLLISION====================================

bool check_collision(void) {
    for (int i = 0; i < snake.size(); i++) {
        if (player_pos_x == snake[i][0] && player_pos_y == snake[i][1]) {
            gotopos(2 + cashex * 2, 1 + cashey);
            cout << SNAKE;
            return true;
        } 
    }
    if (player_pos_y == HEIGHT+ 1 || player_pos_y == -1) {
        gotopos(2 + cashex * 2, 1 + cashey);
        cout << SNAKE;
        gotopos(2 + player_pos_x * 2, 1 + player_pos_y);
        cout << "-";
        return true;
    }
    else if (player_pos_x == WIDTH + 1 || player_pos_x == -1) {
        gotopos(2 + cashex * 2, 1 + cashey);
        cout << SNAKE;
        gotopos(2 + player_pos_x * 2, 1 + player_pos_y);
        cout << "|";
        return true;
    }
    return false;
}

void display_game_over(void) {
    gotopos((2 + WIDTH * 2) / 2 - 4, (1 + HEIGHT) / 2);
    cout << "Game Over";
    gotopos(0, 2 + HEIGHT);
}
