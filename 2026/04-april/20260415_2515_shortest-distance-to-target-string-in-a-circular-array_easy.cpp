/*
 * Problem 2515: Shortest Distance to Target String in a Circular Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 *
 * Approach: Linear scan through the words array, checking each position where the word matches the target.
 * For each matching index, compute both the clockwise and counter-clockwise distances using modular
 * arithmetic on the circular array, then track the global minimum across all matches.
 *
 * Time Complexity: O(n * m) where n is the number of words and m is the average string length for comparison.
 * Space Complexity: O(1) — only a constant amount of extra variables are used.
 *
 * Runtime: 3 ms
 * Memory: 18.4 MB
 */

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minD = INT_MAX, n = words.size();
        for (int i=0; i< words.size() ; i++) {
            if (words[i] == target) {
                int dist = (i - startIndex + n+1) %(n-1) ;
                minD = min(minD, min((i - startIndex + n) % n, (startIndex - i + n) % n));
            }
        }
        return minD == INT_MAX ? -1 : minD;
    }
};
