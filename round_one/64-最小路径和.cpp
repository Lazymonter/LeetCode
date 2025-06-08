#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid) {
    int height = grid.size();
    int length = 0;
    if(!height || !(length = grid[0].size())) {
        return -1;
    }
    for(int i = 1; i < height; ++i) {
        grid[i][0] += grid[i - 1][0];
    }
    for(int i = 1; i < length; ++i) {
        grid[0][i] += grid[0][i - 1];
    }
    for(int i = 1; i < height; ++i) {
        for(int j = 1; j < length; ++j) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[height - 1][length - 1];
}

int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}