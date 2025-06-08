#include <iostream>
#include <vector>

#include "utils/myutil.hpp"

using namespace std;

vector<int> decode(vector<int> &encoded) {
    int len = encoded.size();
    int sum = 0;
    for (int i = 1; i <= len + 1; ++i) {
        sum ^= i;
    }

    int perms = 0;
    for (int i = 1; i < len; i += 2) {
        perms ^= encoded[i];
    }


    vector<int> ret(len + 1);
    ret[0] = perms ^ sum;
    for (int i = 1; i <= len; ++i) {
        ret[i] = ret[i - 1] ^ encoded[i - 1];
    }

    return ret;
}

int main() {
    vector<int> encoded = {6, 5, 4, 6};
    vector<int> ret = decode(encoded);
    printSingleVec(ret);
    return 0;
}