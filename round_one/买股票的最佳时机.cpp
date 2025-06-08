#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int min = INT_MAX;
    for (int i = 0; i < prices.size(); i++){
        if(prices[i] < min){
            min = prices[i];
        }
        else if(prices[i] - min > max_profit){
            max_profit = prices[i] - min;
        }
        else{
            continue;
        }
    }
    return max_profit;        
}

int main(){
    vector<int> prices = {7, 6, 4, 3, 2, 1};
    cout << maxProfit(prices) << endl;
}