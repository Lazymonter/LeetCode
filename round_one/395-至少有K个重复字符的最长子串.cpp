/*
字符串
分治
滑动窗口
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 分治
int dfs(string &s, int l, int r, int k) {
    vector<int> cnt(26, 0);
    // 统计区间内字符出现的次数
    for (int i = l; i <= r; ++i) {
        cnt[s[i] - 'a'] += 1;
    }

    char split = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 0 && cnt[i] < k) {
            split = i + 'a';
            break;
        }
    }

    if (0 == split) {
        return r -l + 1;
    }

    int i = l;
    int ret = 0;
    while (i <= r) {
        while (i <= r && s[i] == split) {
            i++;
        }

        if (i > r) {
            break;
        }

        int start = i;
        // 分段处理
        while (i <= r && s[i] != split) {
            i++;
        }

        int len = dfs(s, start, i - 1, k);
        ret = max(len, ret);
    }
    return ret;
}

int longestSubstring(string s, int k) {
    int len = s.length();
    return dfs(s, 0, len - 1, k);
}
// 滑动窗口（未更新）



int main() {
    string s = "cababb";
    cout << longestSubstring(s, 2) << endl;
    return 0;
}
