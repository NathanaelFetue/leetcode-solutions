/*
 * Problem #706: Design HashMap (Easy)
 * https://leetcode.com/problems/design-hashmap/
 *
 * Approach: Direct Address Table
 * Since the problem constraints guarantee keys are in the range [0, 10^6],
 * we use a pre-allocated vector of size 1,000,001 as a direct address table.
 * Each index maps directly to its value, with -1 representing an absent key.
 * This eliminates the need for hashing or collision resolution entirely.
 *
 * Time Complexity:
 *   - put, get, remove: O(1) — direct index access into a fixed-size array.
 *
 * Space Complexity:
 *   - O(N) where N = 1,000,001 (maximum key range), fixed regardless of input size.
 *
 * Runtime : 66 ms
 * Memory  : 220.4 MB
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
