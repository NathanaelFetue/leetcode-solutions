/*
 * Problem #706: Design HashMap (Easy)
 * https://leetcode.com/problems/design-hashmap/
 *
 * Approach: Direct Address Table
 * Since keys are constrained to the range [0, 1000000], we use a pre-allocated
 * vector of size 1000001 as a direct address table. Each index maps directly to
 * its value, using -1 as a sentinel to indicate an absent key. This avoids any
 * hashing or collision handling entirely.
 *
 * Time Complexity:
 *   - put, get, remove: O(1) — all operations are direct index accesses.
 *
 * Space Complexity:
 *   - O(N) where N = 1,000,001 (the fixed key range), regardless of insertions.
 *
 * Runtime : 71 ms
 * Memory  : 220.3 MB
 */

class MyHashMap {
    vector<int> mp;
public:
    MyHashMap() : mp(1000001, -1) {}
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};
