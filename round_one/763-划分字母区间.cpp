#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> partitionLables(string S) {
    int last[26];
    int length = S.size();
    for (int i = 0; i < length; ++i) {
        last[S[i] - 'a'] = i;
    }
    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < length; ++i){
        end = max(end, last[S[i] - 'a']);
        if (i == end) {
            result.emplace_back(end - start + 1);
            start = end + 1;
        }
    }
    return result;

}
