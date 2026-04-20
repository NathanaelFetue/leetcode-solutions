/*
 * Problem 2078: Two Furthest Houses With Different Colors
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 *
 * Approach: Brute Force Two-Pointer Enumeration
 * Iterate over all unique pairs (first, second) where first < second using nested pointer traversal.
 * For each pair with different colors, compute the absolute distance and track the maximum found.
 * The outer pointer advances only when the inner pointer exhausts all positions to its right.
 *
 * Time Complexity: O(n^2) - all pairs of indices are considered in the worst case.
 * Space Complexity: O(1) - only a constant number of variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 12.1 MB
 */

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int first=0 , second =1;
        int n = colors.size();
        int best =0;
        while(first < n-1){
            if(colors[first] != colors[second]){
                best = max(best , abs(second-first));
            }
            second++;
            if(second == n) {
                first ++;
                second = first+1;
            }
        }
        return best;
    }
};

