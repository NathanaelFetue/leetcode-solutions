/*
 * Problem #88 - Merge Sorted Array (Easy)
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * Approach: Three-pointer technique merging from the end of both arrays.
 * Start pointers at the last valid elements of nums1 (index m-1) and nums2 (index n-1),
 * and fill nums1 from the back (index m+n-1), placing the larger element each step.
 * Any remaining elements from nums2 are copied over; nums1 leftovers are already in place.
 *
 * Time Complexity: O(m + n) - each element from both arrays is visited exactly once.
 * Space Complexity: O(1) - merge is performed in-place using the extra space in nums1.
 *
 * Runtime: 0 ms
 * Memory: 12.2 MB
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
