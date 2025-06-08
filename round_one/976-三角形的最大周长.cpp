#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int largestPermeter(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = A.size() - 1; i >= 2; --i){
        if (A[i] < A[i - 1] + A[i - 2]) {
            return A[i] + A[i - 1] + A[i - 2];
        }
    }

    return 0;
}

int main() 
{
    vector<int> A = {4, 2, 2};
    vector<int> B = {2, 1, 2};

    cout << largestPermeter(A) << endl;
    cout << largestPermeter(B) << endl;
}