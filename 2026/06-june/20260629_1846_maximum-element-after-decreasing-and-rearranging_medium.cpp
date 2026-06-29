/*
 * Problem #1846: Maximum Element After Decreasing and Rearranging (Medium)
 * https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
 *
 * Approach: Greedy with Sorting
 * Sort the array in ascending order, then greedily assign the largest possible value
 * to each position. The first element is always set to 1, and each subsequent element
 * can be at most 1 greater than the previous assigned value, so we increment the
 * answer only when the current element is large enough to support the next value.
 *
 * Time Complexity : O(n log n) — dominated by the sorting step over n elements.
 * Space Complexity : O(1) — sorting is done in-place and only a constant extra variable is used.
 *
 * Runtime : 12 ms
 * Memory  : 55.2 MB
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= ans + 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
