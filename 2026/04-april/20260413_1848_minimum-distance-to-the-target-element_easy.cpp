/*
 * Problem #1848 - Minimum Distance to the Target Element
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-distance-to-the-target-element/
 *
 * Approach/Algorithm:
 * Perform a single linear scan through the array, checking each element against the target.
 * Whenever a match is found, compute the absolute difference between the current index and
 * the start index, updating the minimum distance if this value is smaller than the current minimum.
 *
 * Time Complexity: O(n) - We iterate through all n elements of the array exactly once.
 * Space Complexity: O(1) - Only a single integer variable is used for tracking the minimum.
 *
 * Runtime: 0 ms
 * Memory: 13.1 MB
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == target) 
                if(abs(i - start) < min) min = abs(i - start);
        }
        return min;
    }
};
