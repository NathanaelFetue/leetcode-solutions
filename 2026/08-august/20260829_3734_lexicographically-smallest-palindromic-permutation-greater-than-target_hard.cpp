/*
 * Problem 3734: Lexicographically Smallest Palindromic Permutation Greater Than Target
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
 *
 * Approach:
 * The key insight to solving this problem is to construct the left half of the palindrome greedily from left to right. At each index, we try placing the smallest available character and verify if a valid completion exists. To check viability, we construct the largest possible palindrome using the remaining unused characters in descending lexicographical order; if even this maximum completion is not strictly greater than the target, then no valid completion exists for this choice. Once our constructed prefix becomes strictly greater than the corresponding target prefix, we can bypass the feasibility checks entirely and greedily fill the remaining positions with the smallest available characters in ascending order to minimize the result.
 *
 * Time Complexity: O(N^2) — where N is the length of the string. We iterate N / 2 times to construct the left half, and at each step, we try up to 26 characters and perform an O(N) string construction and comparison during the feasibility check.
 * Space Complexity: O(N) — to store the prefix and construct temporary palindromic strings of length N during the feasibility checks and the final answer construction.
 *
 * Runtime: 159 ms | Memory: 109.8 MB
 */

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        // Special case: length of 1
        if (n == 1) {
            return s > target ? s : "";
        }

        // Count the frequency of each character
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if it can form a palindrome and record the characters with odd
        // occurrences
        string oddChar = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                // More than one character appears an odd number of times,
                // cannot form a palindrome
                if (oddChar != "") {
                    return "";
                }
                oddChar = string(1, 'a' + i);
            }
            cnt[i] /= 2;  // It takes only half the characters to construct the
                          // left half
        }

        string prefix = "";

        auto check = [&](char c) -> bool {
            string left = prefix;
            left.push_back(c);
            for (int i = 25; i >= 0; i--) {
                left.append(cnt[i], 'a' + i);
            }

            string palindrome = left + oddChar;
            string reversed_left = left;
            reverse(reversed_left.begin(), reversed_left.end());
            palindrome += reversed_left;

            return palindrome > target;
        };

        // Construct the left part of each digit greedily
        for (int i = 0; i < n / 2; i++) {
            bool found = false;
            // Try to place the smallest character in lexicographical order
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }

                cnt[j]--;
                if (check('a' + j)) {
                    // If the constructed palindrome is greater than target,
                    // choose the character
                    prefix.push_back('a' + j);
                    found = true;
                    break;
                } else {
                    cnt[j]++;  // Not meeting the conditions, reset the counter
                }
            }
            if (!found) {
                return "";  // Cannot construct a palindrome larger than target
            }

            if (prefix[i] >
                target[i]) {  // prefix is already greater than target
                string left = prefix;
                for (int j = 0; j < 26; j++) {
                    left.append(cnt[j], 'a' + j);
                }
                string palindrome = left + oddChar;
                string reversed_left = left;
                reverse(reversed_left.begin(), reversed_left.end());
                palindrome += reversed_left;
                return palindrome;
            }
        }

        // Construct the final palindrome string
        string ans = prefix + oddChar;
        string reversed_prefix = prefix;
        reverse(reversed_prefix.begin(), reversed_prefix.end());
        ans += reversed_prefix;
        return ans;
    }
};
