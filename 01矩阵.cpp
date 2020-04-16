#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int raw = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result(raw,vector<int>(col,INT_MAX));
    for(int i = 0;i < raw;i++){
        for(int j = 0;j < col;j++){
            if(matrix[i][j] == 0){
                result[i][j] = 0;
            }
        }
    }
    for(int i = 0;i < raw;i++){
        for(int j = 0;j < col;j++){
            if(i - 1 > 0){
                result[i][j] = min(result[i][j], result[i - 1][j] + 1);
            }
            if(j - 1 > 0){
                result[i][j] = min(result[i][j], result[i][j - 1] + 1);
            }
        }
    }
    for(int i = raw - 1;i >= 0 ;i--){
        for(int j = col - 1;j >= 0;j--){
            if(i + 1 < raw){
                result[i][j] = min(result[i][j], result[i + 1][j] + 1);
            }
            if(j + 1 < col){
                result[i][j] = min(result[i][j], result[i][j + 1] + 1);
            }
        }
    }
    return result;

}

int main(){
    vector<vector<int>> dist = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> result = updateMatrix(dist);
    for(int i = 0;i < dist.size();i++){
        for(int j = 0;j < dist[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}