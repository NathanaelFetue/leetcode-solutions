/*
 * Problem #705 - Design HashSet (Easy)
 * https://leetcode.com/problems/design-hashset/
 *
 * Approach: Separate Chaining Hash Map
 * Uses a fixed-size array of 1000 buckets (vectors) to handle collisions via separate chaining.
 * Each key is mapped to a bucket index using key % SIZE, and the bucket's vector stores all keys that hash to that index.
 * Duplicate prevention is handled by linear scan before insertion; removal uses std::remove with erase idiom.
 *
 * Time Complexity:
 *   - add: O(n/k) average where n = total keys, k = number of buckets (O(1) amortized)
 *   - remove: O(n/k) average for scan and erase
 *   - contains: O(n/k) average for linear scan within bucket
 *
 * Space Complexity: O(n + k) where n = number of stored keys, k = 1000 buckets
 *
 * Runtime: 22 ms | Memory: 47.7 MB
 */

class MyHashSet {
    static const int SIZE = 1000;
    vector<vector<int>> buckets;
    
    int hash(int key) { return key % SIZE; }

public:
    MyHashSet() : buckets(SIZE) {}
    
    void add(int key) {
        int h = hash(key);
        for (int k : buckets[h])
            if (k == key) return;
        buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        auto& b = buckets[h];
        b.erase(std::remove(b.begin(), b.end(), key), b.end());
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (int k : buckets[h])
            if (k == key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
