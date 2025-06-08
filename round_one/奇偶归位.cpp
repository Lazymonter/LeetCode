#include <iostream>
#include <vector>

using namespace std;

void resetArray(vector<int> &array){
    int i = 0;
    int j = 1;
    int len = array.size();
    while(i < len && j < len){
        if(array[i] % 2 == 0){
            i = i + 2;
        }
        if(array[j] % 2 == 1){
            j = j + 2;
        }
        if(array[i] % 2 == 1 && array[j] % 2 == 0){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i = i + 2;
            j = j + 2;
        }
    }
}


int main(){
    vector<int> nums = {1,8,6,2,5,7,8,3};
    resetArray(nums);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}