#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet():hm(hashKey) {

    }
    
    void add(int key) {
        int r = hash(key);
        for (auto iter = hm[r].begin(); iter != hm[r].end(); iter++) {
            if (*iter == key) {
                return;
            }
        }
        hm[r].push_back(key);
    }
    
    void remove(int key) {
        int r = hash(key);
        for (auto iter = hm[r].begin(); iter != hm[r].end(); iter++) {
            if (*iter == key) {
                hm[r].erase(iter);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int r = hash(key);
        for (auto iter = hm[r].begin(); iter != hm[r].end(); iter++) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }
private:
    vector<list<int>> hm;
    static const int hashKey = 769;
    static int hash(int key) {
        return key % hashKey;
    }
};