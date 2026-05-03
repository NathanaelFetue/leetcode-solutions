/*
 * 796. Rotate String
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/rotate-string/
 *
 * Approach: Brute-Force Rotation Check
 * For each possible rotation offset j (0 to n-1), compare every character of s
 * with the corresponding character in goal at index (j+i) % n using modular arithmetic.
 * If all characters match for any offset, s can be rotated to form goal.
 *
 * Time Complexity: O(n^2) - outer loop iterates n rotation offsets, inner loop
 * compares n characters for each offset.
 * Space Complexity: O(1) - only a constant amount of extra variables are used,
 * no additional data structures required.
 *
 * Runtime: 0 ms
 * Memory: 8 MB
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        for (int j = 0; j < n; j++) {
            bool match = true;
            for (int i = 0; i < n; i++) {
                if (s[i] != goal[(j+i) % n]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};
