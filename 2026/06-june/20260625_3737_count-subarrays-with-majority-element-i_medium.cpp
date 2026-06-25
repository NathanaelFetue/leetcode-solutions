/*
 * Problem #3737 - Count Subarrays With Majority Element I (Medium)
 * https://leetcode.com/problems/count-subarrays-with-majority-element-i/
 *
 * Approach: Brute-force enumeration of all subarrays using two nested loops.
 * For each starting index i, expand the subarray to the right tracking the frequency
 * of the target element, and check if it appears more than half the subarray length.
 *
 * Time Complexity: O(n^2) - two nested loops iterate over all subarray pairs.
 * Space Complexity: O(1) - only a constant number of variables are used.
 *
 * Runtime: 53 ms
 * Memory: 39.7 MB
 */

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            int freq = 0;
            for(int j=i ; j<nums.size(); j++){
                if(nums[j]== target) freq++;
                int len = j-i+1;
                if(freq*2 > len) res++;
            }
        }
        return res;
    }
};
