/*
 * Problem 169: Majority Element
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/majority-element/
 *
 * Approach: Boyer-Moore Voting Algorithm
 * We maintain a candidate element and a count. As we iterate through the array,
 * we increment the count if the current element matches the candidate, otherwise
 * we decrement it. When the count reaches zero, we replace the candidate with
 * the current element. The majority element (appearing more than n/2 times)
 * always survives as the final candidate.
 *
 * Time Complexity: O(n) - single pass through the array of n elements.
 * Space Complexity: O(1) - only two variables (candidate and count) are used,
 * regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 28.2 MB
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0] , count = 1;
        for(int i =1; i< nums.size(); i++) {
            if(count ==0) {
                candidate = nums[i];
            }
            count += ( nums[i] == candidate ) ? 1 : -1;
        }
        return candidate;
    }
};
