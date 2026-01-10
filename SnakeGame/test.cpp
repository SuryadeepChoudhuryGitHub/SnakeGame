//#include <iostream>
//#include <chrono>
//#include <thread>
//#include <vector>
//#include <cstdlib>
//#include <conio.h>
//
//using namespace std;
//
//const int speed = 20;
//
//void print_board(void);
//void check_direction(void);
//
//int player_pos_x = 0;
//int player_pos_y = 0;
//vector<vector<int>> board = { {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
//
//int main() {
//    print_board();
//    check_direction();
//    system("cls");
//}
//
//void print_board(void) {
//    cout << "+-----------------------------------------------+" << endl;
//    for (size_t i = 0, h = board.size(); i < h; i++) {
//        cout << '|';
//        for (size_t j = 0, l = board.size(); j < l; j++) {
//            if (board[i][j] == 0) {
//                cout << "  ";
//            }
//            else if (board[i][j] == 1) {
//                cout << " S";
//            }
//        }
//        cout << '|' << endl;
//    }
//    //printf(" %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8])
//    cout << "+-----------------------------------------------+" << endl;
//}
//
//
//void move_up();
//void move_down();
//void move_left();
//void move_right();
//
//void check_direction(void) {
//    cout << "Enrer w,a,s,d: ";
//    //vector<void(*)()> directions = { move_up, move_down, move_left, move_right };
//    char direction = 'd';
//    char current_direction = direction;
//    while (true) {
//        if (_kbhit()) {
//            direction = _getch();
//            if (direction == 'w') {
//                current_direction = direction;
//                move_up();
//            }
//            else if (direction == 'a') {
//                current_direction = direction;
//                move_left();
//            }
//            else if (direction == 's') {
//                current_direction = direction;
//                move_down();
//            }
//            else if (direction == 'd') {
//                current_direction = direction;
//                move_right();
//            }
//
//        }
//        else {
//            direction = current_direction;
//            if (direction == 'w') {
//                move_up();
//            }
//            else if (direction == 'a') {
//                move_left();
//            }
//            else if (direction == 's') {
//                move_down();
//            }
//            else if (direction == 'd') {
//                move_right();
//            }
//
//        }
//        this_thread::sleep_for(chrono::milliseconds(1000 / speed));
//    }
//
//}
//
//void move_up(void) {
//    if (player_pos_y > 0) {
//        board[player_pos_y - 1][player_pos_x] = board[player_pos_y][player_pos_x];
//        board[player_pos_y][player_pos_x] = 0;
//        player_pos_y--;
//    }
//    system("cls");
//    print_board();
//    return;
//}
//
//void move_down(void) {
//    if (player_pos_y < board.size() - 1) {
//        board[player_pos_y + 1][player_pos_x] = board[player_pos_y][player_pos_x];
//        board[player_pos_y][player_pos_x] = 0;
//        player_pos_y++;
//    }
//    system("cls");
//    print_board();
//    return;
//}
//
//void move_left() {
//    if (player_pos_x > 0) {
//        board[player_pos_y][player_pos_x - 1] = board[player_pos_y][player_pos_x];
//        board[player_pos_y][player_pos_x] = 0;
//        player_pos_x--;
//    }
//    system("cls");
//    print_board();
//    return;
//}
//
//void move_right() {
//    if (player_pos_x < board.size() - 1) {
//        board[player_pos_y][player_pos_x + 1] = board[player_pos_y][player_pos_x];
//        board[player_pos_y][player_pos_x] = 0;
//        player_pos_x++;
//    }
//    system("cls");
//    print_board();
//    return;
//}

//====================================CREATE TAIL====================================
//vector<vector<int>> tail = {{pos_x, pos_y, direction, delay}}
//void add_new_next(int last, vector<variant<int, char>> tail, int diff_x, int diff_y, char direc);
//void add_new_first(vector<variant<int, char>> tail, int diff_x, int diff_y, char direc);

//vector<variant<int, char>> tail = {};

//void add_new_first(vector<variant<int, char>> tail, int diff_x, int diff_y, char direc) {
//    tail.push_back(player_pos_x + diff_x);
//    tail.push_back(player_pos_y + diff_y);
//    tail.push_back(direc);
//    snake.push_back(tail);
//    gotopos(2 + (player_pos_x + diff_x) * 2, 1 + (player_pos_y + diff_y));
//    cout << "S";
//}
//void add_new_next(int last, vector<variant<int, char>> tail, int diff_x, int diff_y, char direc) {
//    int pos_x = get<int>(snake[last][0]) + diff_x;
//    int pos_y = get<int>(snake[last][1]) + diff_y;
//    tail.push_back(pos_x);
//    tail.push_back(pos_y);
//    tail.push_back(direc);
//    snake.push_back(tail);
//    gotopos(2 + (pos_x) * 2, 1 + pos_y);
//    cout << "S";
//}
