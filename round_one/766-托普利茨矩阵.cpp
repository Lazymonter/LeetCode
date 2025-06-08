/*
// 数组
// 问题1：一次最多只能将矩阵的一行加载到内存中
// 将每一行复制到一个连续数组中，随后在读取下一行时，就与内存中此前保存的数组进行比较
// 问题2：一次只能将不完整的一行加载到内存中
// 将整个矩阵竖直切分成若干子矩阵，并保证两个相邻的矩阵至少有一列或一行是重合的，然后判断每个子矩阵是否符合要求
*/

#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix_s(vector<vector<int>> &matrix) {
    int max_height = matrix.size();
    int max_width = matrix[0].size();
    int height = 0, width = 0;
    for (int i = 0; i < max_width; ++i) {
        height = 1;
        width = i + 1;
        while (height < max_height && width < max_width) {
            if (matrix[height][width] != matrix[height - 1][width - 1]){
                return false;
            }
            height++;
            width++;
        }
    }

    for (int i = 1; i < max_height; ++i) {
        height = i + 1;
        width = 1;
        while (height < max_height && width < max_width) {
            if (matrix[height][width] != matrix[height - 1][width - 1]){
                return false;
            }
            height++;
            width++;
        }
    }
    return true;
}

bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    cout << isToeplitzMatrix(matrix) << endl;
    cout << isToeplitzMatrix_s(matrix) << endl;
    return 0;
}