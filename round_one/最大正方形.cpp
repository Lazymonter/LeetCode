#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;


int maximalSquare(vector<vector<char>> &matrix){
    if(matrix.size() == 0 || matrix[0].size() == 0){
        return 0;
    }
    int maxSide = 0;
    int row = matrix.size();
    int column = matrix[0].size();
    vector<vector<int>> dp(row,vector<int>(column,0));
    for(int i = 0;i < row;i++){
        for(int j = 0;j < column;j++){
            if(matrix[i][j] == '1'){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
                }
                maxSide = std::max(maxSide,dp[i][j]);
            }
        }
    }
    return (maxSide * maxSide);
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}