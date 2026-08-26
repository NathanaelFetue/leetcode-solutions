/*
 * Problem 2904: Shortest and Lexicographically Smallest Beautiful String
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 *
 * Approach:
 * Every beautiful substring must start and end with a '1' to minimize its length. By initiating a search only at indices where s[l] == '1', we can expand a right pointer 'r' until exactly 'k' ones are encountered. Once the k-th '1' is found, we capture this substring as a candidate and immediately break, as any further rightward expansion would only increase the substring's length. We then compare this candidate to our globally tracked best result, prioritizing shorter length first, and then lexicographical order in case of ties.
 *
 * Time Complexity: O(N^2) — For each of the N characters, we potentially scan up to the end of the string to find the k-th '1', followed by an O(N) substring extraction and comparison.
 * Space Complexity: O(N) — Required to store the candidate and final result substrings, which are bounded by the length of the input string.
 *
 * Runtime: 0 ms | Memory: 8.5 MB
 */

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.size();

        for (int l = 0; l < n; l++) {
            if (s[l] != '1') continue;
            
            int ones = 0;
            for (int r = l; r < n; r++) {
                if (s[r] == '1') ones++;
                
                if (ones == k) {
                    string candidate = s.substr(l, r - l + 1);
                    if (res.empty() || candidate.size() < res.size() ||
                       (candidate.size() == res.size() && candidate < res))
                        res = candidate;
                    break; 
                }
            }
        }
        return res;
    }
};
