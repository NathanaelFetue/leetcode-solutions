/*
 * Problem 3120: Count the Number of Special Characters I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-the-number-of-special-characters-i/
 *
 * Approach: Hash Set Intersection
 * Separate all characters into two unordered sets: one for lowercase letters
 * and one for uppercase letters (stored as their lowercase equivalents).
 * Then count how many lowercase letters also appear in the uppercase set,
 * which identifies letters present in both cases (special characters).
 *
 * Time Complexity: O(n) - single pass through the string to build sets,
 * plus O(26) at most to iterate over the lowercase set.
 * Space Complexity: O(1) - sets hold at most 26 distinct alphabet characters.
 *
 * Runtime: 3 ms
 * Memory: 9.7 MB
 */

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;
        for (char c : word) {
            if (islower(c)) lower.insert(c);
            else upper.insert(tolower(c));
        }
        int count = 0;
        for (char c : lower)
            if (upper.count(c)) count++;
        return count;
    }
};
