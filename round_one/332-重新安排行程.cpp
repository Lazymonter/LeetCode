#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include "utils/myutil.hpp"

using namespace std;

//求解欧拉回路

unordered_map<string, priority_queue<string, vector<string>, greater<string>>> interMap;

vector<string> result;

void dfs(const string &cur) {
    while (interMap.count(cur) && !interMap[cur].empty()) {
        string temp = interMap[cur].top();
        interMap[cur].pop();
        dfs(move(temp));
    }
    result.emplace_back(cur);
}

void findItinerary(vector<vector<string>> &tickets) {
    for (auto &&it : tickets) {
        interMap[it[0]].emplace(it[1]);
    }
    dfs("JFK");

    reverse(result.begin(), result.end());
    return;
}

int main() {
    vector<vector<string>> data = {
        {"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}
    };
    findItinerary(data);
    printSingleVec(result);
    return 0;
}