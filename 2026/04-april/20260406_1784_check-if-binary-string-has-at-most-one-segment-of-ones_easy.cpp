/*
 * Problem 1784: Check if Binary String Has at Most One Segment of Ones
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 *
 * Approach: Single-pass linear scan tracking whether a '0' has been encountered.
 * If a '1' is found after a '0' has already been seen, it means a second segment
 * of ones has started, so we return false immediately. Otherwise return true.
 *
 * Time Complexity: O(n) - single pass through the string of length n.
 * Space Complexity: O(1) - only a single boolean flag is used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 8.3 MB
 */

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZero = false;
        for (int i=0; i< s.size(); i++) {
            if (s[i] == '1' ) {
                if (seenZero) return false;
            } else {
                seenZero = true;
            }
        }
        return true;

    }
};
