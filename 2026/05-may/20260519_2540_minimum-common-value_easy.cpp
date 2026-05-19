/*
 * Problem #2540 - Minimum Common Value (Easy)
 * https://leetcode.com/problems/minimum-common-value/
 *
 * Approach: Two-pointer technique on two sorted arrays.
 * Start both pointers at index 0. If values match, return the common value immediately.
 * If nums1[i] < nums2[j], advance i; otherwise advance j to converge toward a match.
 *
 * Time Complexity: O(n + m) where n and m are the lengths of nums1 and nums2.
 * Each pointer traverses its array at most once, so the total work is linear.
 *
 * Space Complexity: O(1) — only two integer pointers are used; no extra data structures.
 *
 * Runtime: 0 ms
 * Memory: 54.6 MB
 */

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) return nums1[i];
            if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};
