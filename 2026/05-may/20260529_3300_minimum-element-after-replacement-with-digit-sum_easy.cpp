/*
 * Problem 3300: Minimum Element After Replacement With Digit Sum
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
 *
 * Approach: Iterate through each element in the array and compute its digit sum
 * by repeatedly extracting the last digit via modulo 10 and dividing by 10.
 * Track the minimum digit sum encountered across all elements and return it.
 *
 * Time Complexity: O(n * d) where n is the number of elements and d is the
 * maximum number of digits in any element (at most 6 for int range used here).
 * Effectively O(n) since d is bounded by a small constant.
 *
 * Space Complexity: O(1) — only a constant number of extra variables are used
 * regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 27.7 MB
 */

class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int i=0; i<nums.size();i++) {
            int tmp = nums[i];
            int locSum = 0;
            while(tmp !=0) {
                locSum += tmp%10;
                tmp /=10;
            }
            res = min(res ,locSum);
        }
        return res;
    }
};
