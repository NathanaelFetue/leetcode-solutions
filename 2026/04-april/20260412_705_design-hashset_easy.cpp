/*
 * Problem #705 - Design HashSet (Easy)
 * https://leetcode.com/problems/design-hashset/
 *
 * Approach: Direct Address Table (Boolean Array)
 * Since the key range is bounded [0, 1000000], a boolean vector of size 1000001
 * is pre-allocated where index represents the key and value represents presence.
 * Add sets the index to true, remove sets it to false, and contains returns the value.
 *
 * Time Complexity:
 *   - add()      : O(1) - direct index write
 *   - remove()   : O(1) - direct index write
 *   - contains() : O(1) - direct index read
 *
 * Space Complexity: O(N) where N = 1,000,001 (fixed upper bound of key range)
 *
 * Runtime : 8 ms
 * Memory  : 50.5 MB
 */

class MyHashSet {
    vector<bool> data;
public:
    MyHashSet() : data(1000001, false) {}
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
