#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool searchMatric(vector<vector<int>> &matrix, int target) {
    auto tar = upper_bound(matrix.begin(), matrix.end(), target, [](const int a, const vector<int> &b){
            return a < b[0];
        }
    );

    if (tar == matrix.begin()) {
        return false;
    }

    --tar;
    return binary_search(tar->begin(), tar->end(), target);
}


int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatric(matrix, 3) << endl;
    cout << searchMatric(matrix, 13) << endl;
    return 0;
}