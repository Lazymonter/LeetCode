/*
dp
*/

#include <iostream>
#include <vector>
#include <algorithm>


const int MODULO = 1000000007;

int numWays(int steps, int arrLen) {
    int maxColum = std::min(arrLen - 1, steps >> 1);
    std::vector<int> dp(maxColum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= steps; ++i) {
        std::vector<int> dpNext(maxColum + 1, 0);
        for (int j = 0; j <= maxColum; ++j) {
            dpNext[j] = dp[j];
            if (j - 1 >= 0) {
                dpNext[j] = (dpNext[j] + dp[j - 1]) % MODULO;
            }

            if (j + 1 <= maxColum) {
                dpNext[j] = (dpNext[j] + dp[j + 1]) % MODULO;
            }
        }

        dp = dpNext;
    }

    return dp[0];
}


int main() {
    std::cout << numWays(3, 2) << std::endl;
    std::cout << numWays(2, 4) << std::endl;
    std::cout << numWays(4, 2) << std::endl;
    return 0;
}