/*
回溯
动态规划

*/

#include <iostream>
#include <vector>
#include <string>

#include "utils/myutil.hpp"

using namespace std;
// 回溯+ 动态规划预处理
class solution_a {
private:
    vector<vector<string>> ret;
    vector<vector<int>> f;
    vector<string> ans;
    int len = 0;
public:
    void dfs(string &s, int i) {
        if (i == len) {
            ret.push_back(ans);
            return;
        }

        for (int j = i;j < len;j++) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        len = s.length();
        f.assign(len, vector<int>(len, 1));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j  < len; j++) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};

// 回溯+记忆化搜索


int main() {
    solution_a *so = new solution_a();
    vector<vector<string>> ret = so->partition("aaba");
    printMultiVec(ret);
    return 0;
}