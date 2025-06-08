#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


vector<vector<int>> merge_self(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),[](vector<int> &a,vector<int> &b){return a[0] < b[0];});
    if(intervals.size() == 0){
        return intervals;
    }
    stack<vector<int>> st;
    st.push(intervals[0]);
    for(vector<vector<int>>::iterator iter = intervals.begin() + 1;iter != intervals.end();iter++) {
        vector<int> in_stack = st.top();
        if(in_stack[1] >= (*iter)[0]){
            in_stack[1] = (*iter)[1] > in_stack[1] ? (*iter)[1] : in_stack[1];
            st.pop();
            st.push(in_stack);
        }
        else{
            st.push(*iter);
        }
    }
    vector<vector<int>> result(st.size());
    for(int i = st.size() - 1;i >= 0;i--){
        result[i] = st.top();
        st.pop();
    }
    return result;
        
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),[](vector<int> &a,vector<int> &b){return a[0] < b[0];});
    if(intervals.size() == 0){
        return intervals;
    }
    vector<vector<int>> result;
    for(int i = 0;i < intervals.size();i++) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if(result.empty() || left > result.back()[1]){
            result.push_back({left,right});
        }
        else{
            result.back()[1] = right > result.back()[1] ? right : result.back()[1];
        }
    }
    return result;
        
}

int main(){
    vector<vector<int>> intervals = {{2,6},{1,3},{10,13},{8,10}};
    vector<vector<int>> result = merge(intervals);
    for(vector<int> i : result){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}