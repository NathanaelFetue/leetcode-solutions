/*
 * Problem #11 - Container With Most Water (Medium)
 * https://leetcode.com/problems/container-with-most-water/
 *
 * Approach: Two-pointer technique starting from both ends of the array.
 * At each step, calculate the water held between the two pointers using the
 * shorter height as the limiting factor. Move the pointer with the smaller
 * height inward, since keeping the taller height gives the best chance of
 * finding a larger area with a closer but taller boundary.
 *
 * Time Complexity : O(n) - single pass through the array with two pointers
 * Space Complexity: O(1) - only a constant number of variables used
 *
 * Runtime : 0 ms
 * Memory  : 63 MB
 */

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int best = 0;

        while (l < r) {
            int water = min(heights[l], heights[r]) * (r - l);
            best = max(best, water);

            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return best;
    }
};
