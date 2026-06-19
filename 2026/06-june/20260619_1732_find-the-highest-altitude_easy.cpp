/*
 * Problem #1732: Find the Highest Altitude
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-the-highest-altitude/
 *
 * Approach: Prefix Sum with Running Maximum
 * We simulate the altitude at each point by maintaining a running cumulative altitude.
 * At each step, we compute the current altitude relative to the start (altitude 0) and track the maximum seen so far.
 * Note: the variable 'deb' accumulates the negative sum, so (gain[i] - deb) effectively gives the current altitude.
 *
 * Time Complexity: O(n) - single pass through the gain array of size n.
 * Space Complexity: O(1) - only two integer variables used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 10.8 MB
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestA =0 , deb =0;
        for(int i =0; i<gain.size(); i++){
            highestA = max(highestA , (gain[i] - deb));
            deb = deb - gain[i];
        }

        return highestA;
    }
};
