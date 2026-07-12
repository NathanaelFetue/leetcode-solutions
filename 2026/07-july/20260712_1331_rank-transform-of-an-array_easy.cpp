/*
 * Problem #1331: Rank Transform of an Array (Easy)
 * https://leetcode.com/problems/rank-transform-of-an-array/
 *
 * Approach: Sort and deduplicate a copy of the array, then assign ranks 1..N
 * to each unique value using an unordered_map. Finally, map each original
 * element to its precomputed rank via the hash map.
 *
 * Time Complexity: O(n log n) — dominated by sorting the copied array;
 * hash map insertions and lookups are O(1) amortized.
 *
 * Space Complexity: O(n) — for the sorted/deduplicated copy, the hash map,
 * and the result array, all linear in the input size.
 *
 * Runtime: 35 ms
 * Memory: 44 MB
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); 

        unordered_map<int, int> mp;
        for (int i = 0; i < tmp.size(); i++)
            mp[tmp[i]] = i + 1;

        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++)
            res[i] = mp[arr[i]];

        return res;
    }
};
