/*
hash表
*/
#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils/myutil.hpp"


using namespace std;

vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, vector<int>> m;
    for (auto &pair : adjacentPairs) {
        m[pair[0]].push_back(pair[1]);
        m[pair[1]].push_back(pair[0]);
    }

    int len = adjacentPairs.size() + 1;
    vector<int> ret(len);
    for (auto &adj : m) {
        if (adj.second.size() == 1) {
            ret[0] = adj.first;
            break;
        }
    }

    ret[1] = m[ret[0]][0];

    for (int i = 2; i < len; ++i) {
        auto &adj = m[ret[i - 1]];
        ret[i] = ret[i - 2] == adj[0] ? adj[1] : adj[0];
    }

    return ret;
}

int main() {
    vector<vector<int>> adj = {{2, 1}, {3, 4}, {3, 2}};
    auto ret = restoreArray(adj);
    printSingleVec(ret);
    return 0;
}