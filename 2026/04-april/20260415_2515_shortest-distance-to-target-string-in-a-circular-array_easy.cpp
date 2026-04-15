/*
 * Problem 2515: Shortest Distance to Target String in a Circular Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 *
 * Approach: Linear scan through all words, checking each occurrence of the target string.
 * For each match, compute both the clockwise and counter-clockwise distances using modular
 * arithmetic, then track the global minimum across all occurrences.
 *
 * Time Complexity: O(n * m) where n is the number of words and m is the average string length
 * due to string comparison at each index.
 * Space Complexity: O(1) — only a constant number of extra variables are used regardless of input size.
 *
 * Runtime: 0 ms
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
