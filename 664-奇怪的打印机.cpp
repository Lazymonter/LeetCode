/*
动态规划
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;


int strangePrinter(string s) {
    int len = s.length();
    vector<vector<int>> f(len, vector<int>(len));
    for (int i = len - 1; i >= 0; --i) {
        f[i][i] = 1;
        for (int j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                f[i][j] = f[i][j - 1];
            } else {
                int minn = INT_MAX;
                for (int k = i; k < j; ++k) {
                    minn = min(minn, f[i][k] + f[k + 1][j]);
                }
                f[i][j] = minn;
            }
        }
    }

    return f[0][len - 1];
}


int main() {
    cout << strangePrinter("aaaddd") << endl;
    cout << strangePrinter("adsaaaaswe") << endl;
    return 0;
}