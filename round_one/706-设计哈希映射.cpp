#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap():hm(base) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        for (auto iter = hm[index].begin(); iter != hm[index].end(); iter++) {
            if (iter->first == key) {
                iter->second = value;
                return;
            }
        }
        hm[index].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        for (auto iter = hm[index].begin(); iter != hm[index].end(); iter++) {
            if (iter->first == key) {
                return iter->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        for (auto iter = hm[index].begin(); iter != hm[index].end(); iter++) {
            if (iter->first == key) {
                hm[index].erase(iter);
                return;
            }
        }
    }
    
private:
    vector<list<pair<int, int>>> hm;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
};