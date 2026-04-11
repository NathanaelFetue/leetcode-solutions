/*
 * Problem #3741: Minimum Distance Between Three Equal Elements II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * Approach: Group all indices of each unique value using a hash map, then for each
 * value that appears at least 3 times, slide a window of 3 consecutive indices and
 * compute 2*(last - first) as the cost, tracking the global minimum across all values.
 *
 * The key insight is that for any triple of indices (a, b, c), the minimum total
 * distance is 2*(c - a), since the optimal meeting point lies between a and c.
 *
 * Time Complexity: O(n) - single pass to build the map, then each index is visited
 * once across all groups, making the overall scan linear.
 *
 * Space Complexity: O(n) - the hash map stores all indices, which in the worst case
 * is O(n) when all elements are distinct.
 *
 * Runtime: 359 ms | Memory: 343.5 MB
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
        for (auto& x : mp) {
            if(x.second.size() >=3) {
                    absSum = minDist(x.second);
                    if (absSum < bestVal) bestVal = absSum;
            }
        }

        return bestVal == INT_MAX ? -1 : bestVal;
    }
};
