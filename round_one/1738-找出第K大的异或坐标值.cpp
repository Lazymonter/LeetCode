/*
二维前缀和
排序
快速选择算法（单区间partition）
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



int kthLargestValue(std::vector<std::vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> ma(m + 1, std::vector<int>(n + 1));
    std::vector<int> ret;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ma[i][j] = ma[i - 1][j - 1] ^ ma[i][j - 1] ^ ma[i - 1][j] ^ matrix[i - 1][j - 1];
            ret.push_back(ma[i][j]);
        }
    }

    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), std::greater<int>());

    return ret[k - 1];
}

int main() {
    std::vector<std::vector<int>> matrix = {{5, 2}, {1, 6}};
    std::cout << kthLargestValue(matrix, 1) << std::endl;
    std::cout << kthLargestValue(matrix, 2) << std::endl;
    std::cout << kthLargestValue(matrix, 3) << std::endl;
    std::cout << kthLargestValue(matrix, 4) << std::endl;
    return 0;
}