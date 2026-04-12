/*
 * Problem #705 - Design HashSet
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/design-hashset/
 *
 * Approach: Separate Chaining Hash Set
 * Uses a fixed-size array of 1000 buckets, each holding a vector of integers.
 * Keys are mapped to buckets via modulo hashing (key % 1000), and collisions
 * are resolved by storing all colliding keys in the same bucket vector (chaining).
 * Each operation linearly scans the relevant bucket to add, remove, or check keys.
 *
 * Time Complexity:
 *   - add / remove / contains: O(n/k) average where n = number of keys, k = 1000 buckets.
 *   - Worst case O(n) if all keys hash to the same bucket.
 *
 * Space Complexity: O(n + k) where k = 1000 (bucket array) and n = stored keys.
 *
 * Runtime: 14 ms | Memory: 47.6 MB
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
            if (k == key) return; // déjà présent
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
