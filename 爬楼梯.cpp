#include <iostream>

using namespace std;

//递归
int climbStairs_ori(int n) {
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else{
        return climbStairs_ori(n - 1) + climbStairs_ori(n - 2);
    }        
}
//动态规划优化递归
int climbStairs(int n) {
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else{
        int nums[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 2;
        for(int i = 3;i <= n;i++){
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        return nums[n];
    }        
}

int main(){
    int n = 3;
    cout << climbStairs_ori(n) << endl;
    cout << climbStairs(n) << endl;
    return 0;
}