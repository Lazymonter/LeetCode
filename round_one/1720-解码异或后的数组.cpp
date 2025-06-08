/*
异或
归零律：a^a=0
恒等律：a^0=a
交换律：a^b=b^a
结合律：a^b^c=a^(b^c)=(a^b)^c
自反：a^b^a=b
d=a^b^c -> a=d^b^c
*/

#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

vector<int> decode(vector<int> &encoded, int first) {
    int len = encoded.size() + 1;
    vector<int> result(len);
    result[0] = first;
    for (int i = 1; i < len; ++i) {
        result[i] = result[i - 1] ^ encoded[i - 1];
    }

    return result;
}

int main() {
    vector<int> a = {6, 2, 7, 3};
    int first = 4;
    vector<int> result = decode(a, first);
    printSingleVec(result);
    return 0;
}