#include <iostream>

using namespace std;

class solution_recu{
public:
    double quickMul(double x,long long n){
        if(n == 0){
            return 1.0;
        }
        double y = quickMul(x,n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x,int n){
        long long N = n;
        return N > 0 ? quickMul(x,N) : 1.0 / quickMul(x,-N);
    }
};

class soultion_iter{
public:
    double quickMul(double x,long long n){
        double ans = 1.0;
        double x_contribute = x;
        while(n > 0){
            if(n % 2 == 1){
                ans *= x_contribute;
            }
            x_contribute *= x_contribute;
            n = n / 2;
        }
        return ans;
    }
    double myPow(double x,int n){
        long long N = n;
        return N > 0 ? quickMul(x,N) : 1.0 / quickMul(x,-N);
    }
};


int main(){
    double x = 2.0000;
    int n = -3;
    solution_recu mySolution;
    soultion_iter simSolution;
    cout << mySolution.myPow(x,n) << endl;
    cout << simSolution.myPow(x,n) << endl;
    return 0;
}