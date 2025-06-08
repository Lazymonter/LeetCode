#include <iostream>
#include <unordered_set>

using namespace std;

int getNext(int n){
    int result = 0;
    while(n > 0){
        int d = n % 10;
        n = n / 10;
        result += d * d;
    }
    return result;
}

bool isHappy(int n){
    unordered_set<int> m;
    while(n != 1 && !m.count(n)){
        m.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

int main(int argc, char *argv[]){
    int n = 19;
    cout << isHappy(n) << endl;
    return 0;
}