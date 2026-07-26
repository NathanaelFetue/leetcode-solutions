/*
 * Problem #4: Median of Two Sorted Arrays
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Approach: Merge and Sort
 * The two input arrays are merged into a single array by appending all elements of nums2
 * into nums1. The merged array is then sorted, and the median is computed directly from
 * the middle element(s) based on whether the total length is odd or even.
 *
 * Time Complexity: O((m + n) log(m + n))
 * Sorting the merged array of size m + n dominates the runtime.
 *
 * Space Complexity: O(1) extra (in-place merge into nums1, ignoring input mutation)
 * No additional data structures are allocated beyond reusing nums1.
 *
 * Runtime: 4 ms | Memory: 95.5 MB
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

