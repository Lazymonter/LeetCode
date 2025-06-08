#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> firstMax(vector<int> &ele){
    int len = ele.size();
    vector<int> result(len,0);
    stack<int> a;
    a.push(0);
    int index = 1;
    while(index < len){
        if(!a.empty() && ele[index] > ele[a.top()]){
            result[a.top()] = ele[index];
            a.pop();
        }
        else{
            a.push(index);
            index++;
        }
    }
    while(!a.empty()){
        result[a.top()] = -1;
        a.pop();
    }
    return result;
    
}

int main(){
    vector<int> prices = {7, 9, 4, 5, 2, 1};
    vector<int> result = firstMax(prices);
    for(int i: result){
        cout << i << " ";
    }
    cout << endl;
}