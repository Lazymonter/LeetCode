/*
递归
*/
#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

void loop(vector<vector<int>> &matrix, vector<int> &res, int start_h, int end_h, int start_w, int end_w) {
    for (int i = start_w; i <= end_w; i++) {
        res.push_back(matrix[start_h][i]);
    }

    for (int i = start_h + 1; i <= end_h; i++) {
        res.push_back(matrix[i][end_w]);
    }
    if (start_w < end_w && start_h < end_h) {
        for (int i = end_w - 1; i >= start_w; i--) {
            res.push_back(matrix[end_h][i]);
        }

        for (int i = end_h - 1; i > start_h; --i) {
            res.push_back(matrix[i][start_w]);
        }
    }
    ++start_h;
    --end_h;
    ++start_w;
    --end_w;
    if (start_h > end_h || start_w > end_w) {
        return;
    }
    loop(matrix, res, start_h, end_h, start_w, end_w);

}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<int> res;
    loop(matrix, res, 0, height - 1, 0, width - 1);
    return res;
}

int main() {
    vector<vector<int>> m = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res= spiralOrder(m);
    printSingleVec(res);
    return 0;
}