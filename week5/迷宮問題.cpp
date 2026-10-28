
#include <iostream>
using namespace std;

const int SIZE = 10;

char maze[SIZE][SIZE];
bool visited[SIZE][SIZE] = {false};

// 右、上、左、下
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

// Stack 裡面存放的位置和方向
struct Element {
    int row;
    int col;
    int dir;
};

Element st[100];
int top = -1;

// Push
void push(int row, int col, int dir) {
    ++top;
    st[top] = {row, col, dir};
}

// Pop
void pop() {
    --top;
}

// 判斷是否能走
bool canMove(int row, int col) {
    if (row < 0 || row >= SIZE ||
        col < 0 || col >= SIZE) {
        return false;
    }

    return maze[row][col] == '0' &&
           !visited[row][col];
}

// DFS + Backtracking
bool findPath() {
    // 起點 (8,8)
    push(8, 8, 0);
    visited[8][8] = true;
    maze[8][8] = 'S';

    while (top >= 0) {
        Element &current = st[top];

        int row = current.row;
        int col = current.col;

        // 找到出口
        if (row == 1 && col == 1) {
            maze[row][col] = 'X';
            return true;
        }

        // 四個方向都走不通，回溯
        if (current.dir == 4) {
            if (row != 8 || col != 8) {
                maze[row][col] = 'D';
            }

            pop();
            continue;
        }

        // 取得目前方向，然後改成下一個方向
        int dir = current.dir;
        current.dir++;

        int nextRow = row + dr[dir];
        int nextCol = col + dc[dir];

        if (canMove(nextRow, nextCol)) {
            visited[nextRow][nextCol] = true;
            maze[nextRow][nextCol] = 'G';

            push(nextRow, nextCol, 0);
        }
    }

    return false;
}

int main() {
    // 輸入 10x10 迷宮
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> maze[i][j];
        }
    }

    bool found = findPath();

    if (found) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    // 輸出迷宮
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j > 0) cout << " ";
            cout << maze[i][j];
        }
        cout << '\n';
    }

    return 0;
}
