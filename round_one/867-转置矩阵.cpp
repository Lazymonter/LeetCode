/*
数组
*/

#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;


vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int column = matrix[0].size();
    vector<vector<int>> vec(column, vector<int>(row, 0));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            vec[j][i] = matrix[i][j];
        }
    }

    return vec;
}

int main() {
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, res1, res2;
    vector<vector<int>> vec2 = {{1, 2, 3},{4, 5, 6}};
    res1 = transpose(vec);
    res2 = transpose(vec2);
    printMultiVec(res1);
    printMultiVec(res2);
    return 0;
}