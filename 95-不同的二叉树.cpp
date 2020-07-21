#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;
//递归
//注意与96题对比
vector<TreeNode *> generateTrees(int start, int end) {
    if(start > end) {
        return {nullptr};
    }
    vector<TreeNode *> results;
    for(int i = start; i <= end; i++){
        vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
        vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
        for(auto &left : leftTrees){
            for(auto &right : rightTrees){
                TreeNode *temp = new TreeNode(i, left, right);
                results.emplace_back(temp);
            }
        }
    }
    return results;
}
vector<TreeNode *> generateTrees(int n) {
    if(!n) {
        return {};
    }
    return generateTrees(1, n);
}

int main(){
    vector<TreeNode *> result = generateTrees(3);
    return 0;
}