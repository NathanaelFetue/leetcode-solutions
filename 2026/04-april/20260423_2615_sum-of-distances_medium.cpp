/*
 * 2615. Sum of Distances - Medium
 * https://leetcode.com/problems/sum-of-distances/
 *
 * Approach: Prefix and Suffix Sum with Index Grouping
 * Group indices of equal values using a hash map. For each group, perform two passes:
 * a left-to-right pass computes the contribution of all preceding indices to the current index,
 * and a right-to-left pass adds the contribution of all succeeding indices, using prefix/suffix sums to avoid O(n^2) recomputation.
 *
 * For left pass:  arr[i] = index[i] * i - prefixSum
 * For right pass: arr[i] += suffixSum - index[i] * (m - i)
 *
 * Time Complexity: O(n) - each element is processed a constant number of times across grouping and two-pass traversal
 * Space Complexity: O(n) - hash map stores all indices grouped by value, plus output array
 *
 * Runtime: 50 ms
 * Memory: 109.5 MB
 */

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);

        vector<long long> arr(nums.size(), 0);

        for (auto& [val, indices] : mp) {
            int m = indices.size();
            long long prefSum = 0;
            for (int i = 0; i < m; i++) {
                arr[indices[i]] = (long long)indices[i] * i - prefSum;
                prefSum += indices[i];
            }
            long long sufSum = 0;
            for (int i = m-1; i >= 0; i--) {
                sufSum += indices[i];
                arr[indices[i]] += sufSum - (long long)indices[i] * (m - i);
            }
        }
        return arr;
    }
};
