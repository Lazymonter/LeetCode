#include <iostream>


using namespace std;

int hammingWeight(uint32_t n) {
    int ret = 0;
    while(n) {
        n &= (n - 1);
        ret++;
    }
    return ret;
}