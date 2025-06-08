/*
一维前缀和
二维前缀和
*/
#include <iostream>
#include <vector>

using namespace std;
// 一维前缀和
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if (len > 0) {
            int n = matrix[0].size();
            sum.resize(len, vector<int>(n + 1));
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < n; ++j) {
                    sum[i][j + 1] = sum[i][j] + matrix[i][j]; 
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int i = row1; i <= row2; ++i) {
            ret += sum[i][col2 + 1] - sum[i][col1];
        }
        
        return ret;
    }
private:
    vector<vector<int>> sum;
};
// 二维前缀和
class NumMatrix2{
public:
    vector<vector<int>> sums;
    NumMatrix2(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; ++j) {
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
                }
            } 
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2  + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }

};