#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid = {
    {9,0,6,0,7,0,4,0,3},
    {0,0,0,4,0,0,2,0,0},
    {0,7,0,0,2,3,0,1,0},
    {5,0,0,0,0,0,1,0,0},
    {0,4,0,2,0,8,0,6,0},
    {0,0,3,0,0,0,0,0,5},
    {0,3,0,7,0,0,0,5,0},
    {0,0,7,0,0,5,0,0,0},
    {4,0,5,0,1,0,7,0,8}
};

bool possible(int row, int column, int number) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == number) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[i][column] == number) return false;
    }

    int x = (column / 3) * 3;
    int y = (row / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[y + i][x + j] == number) return false;
        }
    }

    return true;
}

bool solve() {
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {
            if (grid[row][column] == 0) {
                for (int number = 1; number <= 9; number++) {
                    if (possible(row, column, number)) {
                        grid[row][column] = number;
                        if (solve()) return true;
                        grid[row][column] = 0;
                    }
                }
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    if (solve()) {
        for (const auto& row : grid) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
