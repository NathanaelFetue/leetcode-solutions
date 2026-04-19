/*
 * 1855. Maximum Distance Between a Pair of Values
 * Difficulty: Medium
 * https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 *
 * Approach: Two-Pointer Technique
 * Use two pointers, one for each array, starting at index 0. If nums1[left] <= nums2[right],
 * the pair is valid so we update the result with (right - left) and advance right to explore
 * further. Otherwise, we advance left to find a smaller value in nums1.
 *
 * Time Complexity: O(n + m) - each pointer traverses its respective array at most once,
 * where n = nums1.size() and m = nums2.size().
 *
 * Space Complexity: O(1) - only a constant number of variables are used regardless of input size.
 *
 * Runtime: 4 ms
 * Memory: 102.2 MB
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, left = 0, right = 0;
        int n = nums1.size(), m = nums2.size();
        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                res = max(res, right - left);
                right++;
            } else {
                left++;
            }
        }
        return res;
    }
};
