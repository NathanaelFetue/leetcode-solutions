/*
 * Problem #4 - Median of Two Sorted Arrays
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Approach: Merge and Sort
 * The two input arrays are merged into a single array by appending nums2 to the end of nums1.
 * The merged array is then sorted, and the median is computed directly based on whether the total length is odd or even.
 * For odd length, the middle element is returned; for even length, the average of the two middle elements is returned.
 *
 * Time Complexity: O((m + n) log(m + n))
 * Sorting the combined array of size m + n dominates the overall time complexity.
 *
 * Space Complexity: O(1) auxiliary (excluding input modification)
 * The merge is done in-place by extending nums1; no additional data structures are used.
 *
 * Runtime: 3 ms
 * Memory: 95.7 MB
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end() , nums2.begin(), nums2.end());
        sort(nums1.begin() , nums1.end());

        int mid = (nums1.size())/2;
        if(nums1.size()%2 == 1) return (double)nums1[mid];
        return (double) (nums1[mid-1] + nums1[mid])/2.0;
        
    }
};

