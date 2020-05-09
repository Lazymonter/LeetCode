#include <iostream>


using namespace std;

int mySqrt(int x){
    int left = 0;
    int right = x;
    int res = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if((long long)mid * mid <= x){
            res = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return res;
}

int main(){
    cout << mySqrt(10) << endl;
    return 0;
}