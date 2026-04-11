/*
 * Problem #3741 - Minimum Distance Between Three Equal Elements II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * Approach: Group indices of each unique value using a hash map, then for each
 * value that appears at least 3 times, slide a window of 3 consecutive indices
 * and compute the cost as 2 * (last - first), tracking the global minimum.
 * The cost formula 2*(c-a) derives from placing a meeting point optimally
 * between three sorted positions a, b, c, minimizing |x-a|+|x-b|+|x-c|.
 *
 * Time Complexity: O(n) - single pass to build the map, then linear scan over
 * all stored indices (total indices across all groups equals n).
 * Space Complexity: O(n) - hash map stores all indices of all elements.
 *
 * Runtime: 521 ms
 * Memory: 381.7 MB
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
