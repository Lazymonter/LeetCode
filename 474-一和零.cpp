#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> getNums(string &str) {
    vector<int> ret(2);
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        ++ret[str[i] - '0'];
    }
    return ret;
}

int findMaxForm(vector<string> &strs, int m, int n) {
    int len = strs.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < len; ++i) {
        vector<int> zeroOnes = getNums(strs[i]);
        int zero = zeroOnes[0];
        int one = zeroOnes[1];
        for (int j = m; j >= zero; --j) {
            for (int k = n; k >= one; --k) {
                dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
            }
        }
    }

    return dp[m][n];
}


int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(strs, 5, 3) << endl;
    return 0;
}