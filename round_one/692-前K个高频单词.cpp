/*
hash表+排序
优先队列
首次遍历无法避免
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> m;
    for (auto &word : words) {
        m[word]++;
    }

    auto compare = [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> que(compare);
    for (auto &i : m) {
        que.emplace(i);
        if (que.size() > k) {
            que.pop();
        }
    }

    vector<string> ret(k);
    for (int i = k - 1; i >= 0; --i) {
        ret[i] = que.top().first;
        que.pop();
    }

    return ret;
}
