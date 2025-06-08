#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

// 往后挪一位，后面计算不用多异或开始值
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int len = arr.size();
    vector<int> search(len + 1);
    for (int i = 1; i <= len; ++i) {
        search[i] = arr[i - 1] ^ search[i - 1];
    }

    vector<int> ret;
    for (auto &a : queries) {
        ret.push_back(search[a[0]] ^ search[a[1]  + 1]);
    }

    return ret;
}

vector<int> xorQueries_s(vector<int> &arr, vector<vector<int>> &queries) {
    int len = arr.size();
    vector<int> search(len);
    for (int i = 1; i < len; ++i) {
        search[i] = arr[i] ^ search[i - 1];
    }

    vector<int> ret;
    for (auto &a : queries) {
        ret.push_back(search[a[0]] ^ search[a[1]] ^ arr[a[0]]);
    }

    return ret;
}


int main() {
    vector<int> arr = {4, 8, 2, 10};
    vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};

    vector<int> ret = xorQueries_s(arr, queries);

    printSingleVec(ret);

    return 0;
}