/*
 * Problem 2515: Shortest Distance to Target String in a Circular Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 *
 * Approach: Linear scan with circular distance calculation.
 * Iterate through all words and for each match with the target, compute both the
 * clockwise and counter-clockwise distances using modular arithmetic, then track the minimum.
 * The circular distance in either direction is computed as (i - start + n) % n and (start - i + n) % n.
 *
 * Time Complexity: O(n * m) where n is the number of words and m is the average string length for comparisons.
 * Space Complexity: O(1) — only a constant number of variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 18.3 MB
 */

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minD = INT_MAX, n = words.size();
        for (int i=0; i< words.size() ; i++) {
            if (words[i] == target) {
                minD = min(minD, min((i - startIndex + n) % n, (startIndex - i + n) % n));
            }
        }
        return minD == INT_MAX ? -1 : minD;
    }
};
