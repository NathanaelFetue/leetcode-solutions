/*
 * Problem 2784: Check if Array is Good
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-if-array-is-good/
 *
 * Approach: Frequency Count Validation
 * Find the maximum element n, which must equal nums.size()-1 for a valid 'good' array.
 * Count the frequency of each element; every value from 1 to n-1 must appear exactly once,
 * and n must appear exactly twice. Any element exceeding n immediately invalidates the array.
 *
 * Time Complexity: O(n) - single pass to find max, one pass to build frequency array,
 * and one pass to validate frequencies, all linear in the size of the input.
 *
 * Space Complexity: O(n) - auxiliary frequency array of size n+1 proportional to the max element.
 *
 * Runtime: 0 ms
 * Memory: 27.2 MB
 */

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        if (nums.size() != n + 1) return false;
        
        vector<int> freq(n + 1, 0);
        for (int x : nums) {
            if (x > n) return false;
            freq[x]++;
        }
        
        for (int i = 1; i < n; i++)
            if (freq[i] != 1) return false;
        
        return freq[n] == 2;
    }
};
