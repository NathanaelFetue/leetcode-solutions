/*
 * Problem #3741 - Minimum Distance Between Three Equal Elements II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * Approach: Group indices of each unique value using a hash map, then for each
 * value that appears at least three times, slide a window of three consecutive
 * indices and compute the cost as 2*(c - a), tracking the global minimum.
 * The formula 2*(c - a) represents the total movement cost to bring three
 * elements together at the optimal meeting point between indices a and c.
 *
 * Time Complexity: O(n) - single pass to build the map, then linear scan over
 * all stored indices (total index entries = n across all keys).
 *
 * Space Complexity: O(n) - hash map stores all indices, up to n entries total.
 *
 * Runtime: 494 ms | Memory: 381.9 MB
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
