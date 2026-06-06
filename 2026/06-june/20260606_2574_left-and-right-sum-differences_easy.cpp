/*
 * Problem 2574: Left and Right Sum Differences (Easy)
 * https://leetcode.com/problems/left-and-right-sum-differences/
 *
 * Approach: Prefix and Suffix Sum Arrays
 * Build a left prefix sum array where left[i] is the sum of all elements before index i,
 * and a right suffix sum array where right[i] is the sum of all elements after index i.
 * The answer for each index is the absolute difference between its corresponding left and right values.
 *
 * Time Complexity: O(n) - three separate linear passes over the array of size n.
 * Space Complexity: O(n) - three auxiliary arrays (left, right, ans) each of size n.
 *
 * Runtime: 0 ms
 * Memory: 15.2 MB
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0), ans(n);

        for (int i = 1; i < n; i++)
            left[i] = left[i-1] + nums[i-1];

        for (int i = n-2; i >= 0; i--)
            right[i] = right[i+1] + nums[i+1];

        for (int i = 0; i < n; i++)
            ans[i] = abs(left[i] - right[i]);

        return ans;
    }
};
