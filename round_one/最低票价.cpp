#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int mincostTickets(vector<int> &days,vector<int> &costs){
    int last = days[days.size() - 1];
    vector<int> dp(last + 1,0);
    int idx = 0;
    for(int i = 1;i <= last;i++){
        if(i == days[idx]){
            int oneday = i - 1;
            int sevendays = i - 7 > 0 ? i - 7 : 0;
            int thritydays = i - 30 > 0 ? i - 30 : 0;

            dp[i] = min(min(dp[oneday] + costs[0],dp[sevendays] + costs[1]),dp[thritydays] + costs[2]);
            idx++;
        }
        else{
            dp[i] = dp[i - 1];
        }
    }
    return dp[last];
}

int main(){
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};
    cout << mincostTickets(days,costs) << endl;
}