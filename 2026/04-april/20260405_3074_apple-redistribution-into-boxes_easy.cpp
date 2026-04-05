/*
 * Problem 3074: Apple Redistribution into Boxes
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/apple-redistribution-into-boxes/
 *
 * Approach/Algorithm:
 * First, compute the total number of apples using accumulate. Then sort the box
 * capacities in descending order so we greedily pick the largest boxes first.
 * Iterate through sorted capacities, accumulating capacity until it meets or
 * exceeds the total apple count, returning the number of boxes used.
 *
 * Time Complexity: O(n log n + m) where n is the number of boxes (dominated by
 * sort) and m is the number of apple packs (for the accumulate pass).
 *
 * Space Complexity: O(1) extra space beyond the input arrays (sort is in-place).
 *
 * Runtime: 0 ms
 * Memory: 33 MB
 */

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin() , apple.end() , 0); 
        int tmp =0;
        sort(capacity.begin() , capacity.end() , greater<int>());
        int i=0;
        while (tmp < sum) {
            tmp += capacity[i];
            i++;
        }
        return i;
    }
};
