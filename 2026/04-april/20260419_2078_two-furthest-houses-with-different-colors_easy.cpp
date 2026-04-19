/*
 * Problem 2078: Two Furthest Houses With Different Colors
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 *
 * Approach: Brute-force two-pointer enumeration of all pairs (i, j) where i < j.
 * For each pair, if the colors at both indices differ, compute the distance and
 * track the maximum. The outer pointer advances when the inner pointer exhausts
 * all positions to its right.
 *
 * Time Complexity: O(n^2) - every unique pair of indices is visited once,
 * resulting in n*(n-1)/2 comparisons in the worst case.
 *
 * Space Complexity: O(1) - only a constant number of integer variables are used
 * regardless of input size.
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
