/*
 * 2452. Words Within Two Edits of Dictionary
 * Difficulty: Medium
 * https://leetcode.com/problems/words-within-two-edits-of-dictionary/
 *
 * Approach: Brute-force comparison with a character-level diff helper.
 * For each query, iterate through every dictionary word and count differing
 * characters at matching indices. If the diff count is <= 2, the query is valid.
 *
 * Time Complexity: O(Q * D * L) where Q = number of queries, D = dictionary size,
 * and L = word length. Each pair of words is compared character by character.
 *
 * Space Complexity: O(Q) for the result vector storing matched query words.
 * No additional auxiliary data structures are used.
 *
 * Runtime: 9 ms
 * Memory: 12.5 MB
 */

class Solution {
public:
    int diff(string& a, string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) count++;
        return count;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (string& q : queries) {
            for (string& d : dictionary) {
                if (diff(q, d) <= 2) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};
