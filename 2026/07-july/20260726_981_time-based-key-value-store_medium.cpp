/*
 * 981. Time Based Key-Value Store
 * Difficulty: Medium
 * https://leetcode.com/problems/time-based-key-value-store/
 *
 * Approach: Uses an unordered_map where each key maps to a vector of (timestamp, value) pairs stored in chronological order. The set operation appends entries in order, and the get operation performs binary search on the timestamp-sorted vector to find the largest timestamp less than or equal to the queried timestamp. This leverages the guarantee that timestamps are strictly increasing to enable efficient binary search.
 *
 * Time Complexity:
 *   - set: O(1) amortized per call
 *   - get: O(log n) per call, where n is the number of entries for a given key
 *
 * Space Complexity: O(n * m) where n is the number of unique keys and m is the average number of timestamp entries per key
 *
 * Runtime: 69 ms
 * Memory: 137 MB
 */

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        auto& vec = mp[key];

        int left = 0, right = vec.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

