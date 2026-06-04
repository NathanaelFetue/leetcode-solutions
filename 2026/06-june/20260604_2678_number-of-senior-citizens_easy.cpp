/*
 * Problem #2678 - Number of Senior Citizens
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/number-of-senior-citizens/
 *
 * Approach/Algorithm:
 * Each string in the details array encodes passenger information in a fixed format where
 * characters at indices 11-12 (0-indexed) represent the passenger's age as a two-digit string.
 * We extract the age substring, convert it to an integer, and count passengers whose age exceeds 60.
 *
 * Time Complexity: O(n) — we iterate through each of the n strings once, performing
 * a constant-time substring extraction and integer conversion per element.
 *
 * Space Complexity: O(1) — only a single integer counter is maintained regardless of input size;
 * the substring created per iteration is temporary and not accumulated.
 *
 * Runtime: 0 ms
 * Memory: 17.4 MB
 */

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string& s : details) {
            int age = stoi(s.substr(11, 2));
            if (age > 60) count++;
        }
        return count;
    }
};
