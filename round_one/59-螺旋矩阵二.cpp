#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

void loop(vector<vector<int>> &matrix, int n, int start_h, int end_h, int start_w, int end_w) {
    for (int i = start_w; i <= end_w; i++) {
        matrix[start_h][i] = n++;
    }

    for (int i = start_h + 1; i <= end_h; i++) {
        matrix[i][end_w] = n++;
    }
    if (start_w < end_w && start_h < end_h) {
        for (int i = end_w - 1; i >= start_w; i--) {
            matrix[end_h][i] = n++;
        }

        for (int i = end_h - 1; i > start_h; --i) {
            matrix[i][start_w] = n++;
        }
    }
    ++start_h;
    --end_h;
    ++start_w;
    --end_w;
    if (start_h > end_h || start_w > end_w) {
        return;
    }
    loop(matrix, n, start_h, end_h, start_w, end_w);

}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    loop(res, 0, 0, n - 1, 0, n - 1);
    return res;
}

int main() {
    int m = 3;
    vector<vector<int>> res= generateMatrix(m);
    printMultiVec(res);
    return 0;
}