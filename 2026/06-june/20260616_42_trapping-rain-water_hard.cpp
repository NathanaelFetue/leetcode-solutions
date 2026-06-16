/*
 * Problem #42 - Trapping Rain Water (Hard)
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Approach: Precomputed Prefix/Suffix Max Arrays
 * For each index, the water trapped is determined by the minimum of the maximum height
 * to its left and to its right, minus the height at that index. We precompute two arrays,
 * maxL and maxR, storing the running max from the left and right respectively, then
 * accumulate the trapped water in a single pass using these arrays.
 *
 * Time Complexity : O(n) - Three linear passes over the height array (left max, right max, sum).
 * Space Complexity: O(n) - Two auxiliary arrays of size n to store left and right max heights.
 *
 * Runtime : 0 ms
 * Memory  : 27.4 MB
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxL(n), maxR(n);

        maxL[0] = height[0];
        for (int i = 1; i < n; i++)
            maxL[i] = max(maxL[i-1], height[i]);

        maxR[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
            maxR[i] = max(maxR[i+1], height[i]);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += max(0, min(maxL[i], maxR[i]) - height[i]);

        return sum;
    }
};
