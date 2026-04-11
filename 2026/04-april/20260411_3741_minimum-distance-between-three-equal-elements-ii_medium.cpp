/*
 * Problem #3741 - Minimum Distance Between Three Equal Elements II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * Approach: Group indices of each unique value using a hash map, then for every
 * value that appears at least three times, slide a window of three consecutive
 * indices and compute the cost as 2*(last - first). Track the minimum cost across
 * all valid triplets and all values.
 *
 * Time Complexity: O(n) - single pass to build the map, then each index is
 * visited at most once across all groups during the sliding window scan.
 *
 * Space Complexity: O(n) - the hash map stores all indices across all unique values,
 * totalling n entries in the worst case.
 *
 * Runtime: 507 ms | Memory: 381.9 MB
 */

class Solution {
public:
    int minDist(vector<int>& indices) {
        int res = INT_MAX;
        for (int i = 0; i < indices.size() - 2; i++) {
            int a = indices[i], b = indices[i+1], c = indices[i+2];
            res = min(res, 2 * (c - a));
        }
        return res;
    }

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int bestVal = INT_MAX , absSum;
        for (auto x : mp) {
            if(x.second.size() >=3) {
                    absSum = minDist(x.second);
                    if (absSum < bestVal) bestVal = absSum;
            }
        }
        return bestVal == INT_MAX ? -1 : bestVal;
    }
};
