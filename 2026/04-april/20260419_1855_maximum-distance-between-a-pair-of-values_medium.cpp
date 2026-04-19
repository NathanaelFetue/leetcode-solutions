/*
 * Problem 1855: Maximum Distance Between a Pair of Values
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 *
 * Approach: Binary Search per Left Pointer
 * For each index `left` in nums1, we binary search in nums2 starting from `left` to find
 * the furthest index `mid` where nums2[mid] >= nums1[left], maximizing (mid - left).
 * Since both arrays are non-increasing, binary search is valid and efficient here.
 *
 * Time Complexity: O(n log m)
 *   - For each of the n elements in nums1, we perform a binary search over m elements in nums2.
 *
 * Space Complexity: O(1)
 *   - Only a constant number of variables are used; no extra data structures.
 *
 * Runtime: 11 ms
 * Memory: 102.3 MB
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0 , n = nums1.size()-1, left=0 , m =nums2.size()-1;
        while(left <= n) {
            int right = m , lo = left;
            while((lo <=right)) {
                int mid = lo+(right -lo) /2;
                if(nums1[left] <= nums2[mid] ) {
                    res = max(res , (mid -left));
                    lo = mid +1;
                } else {
                    right = mid -1;
                }
            }
            left++;
        }
        return res;
    }
};


