#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int calculateMinnimunHP(vector<vector<int>> &dungeon){
    int m = dungeon.size();
    if(!m){
        return 0;
    }
    int n = dungeon[0].size();
    vector<vector<int>> result(m + 1, vector<int>(n + 1, INT_MAX));
    result[m][n - 1] = result[m - 1][n] = 1;
    for(int i = m - 1;i >= 0;i--){
        for(int j = n - 1;j >= 0;j--){
            result[i][j] = max((min(result[i + 1][j], result[i][j + 1]) - dungeon[i][j]), 1);
        }
    }
    
    return result[0][0];
}

int main(){
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, 10, 1}, {10, 30, -5}};
    cout << calculateMinnimunHP(dungeon) << endl;
    return 0;
}