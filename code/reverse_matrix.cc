#include <iostream>
#include <vector>

using namespace std;

void reverse_matrix(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < (n+1)/2;j++) {
            int x = i, y = j;
            int tmp = m[i][j];
            for (int k = 0; k < 3;k++) {
                m[x][y] = m[n- 1 -y][x];
                int pre_y = x;
                x = n - 1- y;
                y = pre_y;
            }
            m[x][y] = tmp;
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (n + 1) / 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}



int main() {
    int n = 3;
    vector<vector<int>> m(n, vector<int>(n, 0));
    int x = 0;
    for (auto &nums : m) {
        for (auto &num : nums) {
            num = x;
            ++x;
        }
    }

    for (auto &nums : m) {
        for (auto num : nums) {
            cout << num << ",";
        }
        cout << endl;
    }
    reverse_matrix(m);
    cout << "\n" << endl;
    for (auto &nums : m) {
        for (auto num : nums) {
            cout << num << ",";
        }
        cout << endl;
    }
    return 0;
}