/*
 * Problem #3488 - Closest Equal Element Queries (Medium)
 * https://leetcode.com/problems/closest-equal-element-queries/
 *
 * Approach: Index Grouping + Binary Search with Circular Distance
 * Group all indices for each unique value using a hash map. For each query index q,
 * binary search within the sorted index list of nums[q] to find the nearest neighbor(s),
 * then compute the minimum circular distance considering wraparound in both directions.
 * Also check the front and back of the index list to handle circular adjacency across ends.
 *
 * Time Complexity: O((n + m) log n)
 *   - Building the map: O(n)
 *   - Each of m queries does a binary search in O(log n), total O(m log n)
 *
 * Space Complexity: O(n)
 *   - Hash map stores all indices, one entry per element in nums
 *
 * Runtime : 215 ms
 * Memory  : 216.8 MB
 */

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        vector<int> ans;
        for (int q : queries) {
            int val = nums[q];
            auto& idx = mp[val];
            if (idx.size() == 1) { ans.push_back(-1); continue; }
            auto it = lower_bound(idx.begin(), idx.end(), q);
            
            int minD = INT_MAX;
            if (it != idx.end()) {
                int r = ((*it == q) && next(it) != idx.end()) ? *next(it) : *it;
                if (r != q) minD = min(minD, min((r-q+n)%n, (q-r+n)%n));
            }
            if (it != idx.begin()) {
                int l = *prev(it);
                if (l != q) minD = min(minD, min((l-q+n)%n, (q-l+n)%n));
            }
            if (idx.front() != q) minD = min(minD, min((idx.front()-q+n)%n, (q-idx.front()+n)%n));
            if (idx.back() != q) minD = min(minD, min((idx.back()-q+n)%n, (q-idx.back()+n)%n));

            ans.push_back(minD);
        }
        return ans;
    }
};
