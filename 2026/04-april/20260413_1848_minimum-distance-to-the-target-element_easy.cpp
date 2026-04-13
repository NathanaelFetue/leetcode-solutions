/*
 * Problem #1848: Minimum Distance to the Target Element
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-distance-to-the-target-element/
 *
 * Approach/Algorithm:
 * Iterate through the array once, and for every index where the element equals
 * the target value, compute the absolute difference between that index and the
 * given start index, tracking the minimum difference found throughout the scan.
 *
 * Time Complexity: O(n) - single linear pass through the entire nums array
 * where n is the length of the array.
 *
 * Space Complexity: O(1) - only a single integer variable is used to track the
 * minimum distance (the map declared in the code is unused and effectively
 * contributes no meaningful overhead beyond a constant).
 *
 * Runtime: 0 ms
 * Memory: 13.3 MB
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        map <int, int> mp;
        int min = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == target) 
                if(abs(i - start) < min) min = abs(i - start);
        }
        return min;
    }
};
