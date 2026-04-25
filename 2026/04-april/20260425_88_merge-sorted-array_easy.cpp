/*
 * Problem #88: Merge Sorted Array (Easy)
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * Approach: Two-pointer merge from the back.
 * Start three pointers at the last valid element of nums1 (i), last element of nums2 (j),
 * and the last position of the merged array (k). Compare elements from both arrays right
 * to left, placing the larger value at position k and decrementing accordingly. Any
 * remaining elements in nums2 are copied over; remaining nums1 elements are already in place.
 *
 * Time Complexity : O(m + n) - each element from both arrays is visited exactly once.
 * Space Complexity: O(1) - merge is done in-place using the pre-allocated buffer in nums1.
 *
 * Runtime : 0 ms
 * Memory  : 12.3 MB
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
