/*
 * Problem 1081: Smallest Subsequence of Distinct Characters (Medium)
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 * Approach: Greedy stack-based algorithm.
 * First, record the last occurrence index of each character. Then iterate through the string,
 * using a greedy stack: for each character, pop the stack top if the current character is smaller
 * and the top character appears again later, ensuring lexicographic minimality while preserving all distinct characters.
 *
 * Time Complexity: O(n) - single pass to build last-occurrence map, single pass to build result;
 * each character is pushed and popped at most once.
 * Space Complexity: O(1) - the stack and set hold at most 26 distinct characters (bounded constant),
 * and the map holds at most 26 entries.
 *
 * Runtime: 3 ms
 * Memory: 8.8 MB
 */

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> last;
        for (int i = 0; i < s.size(); i++) last[s[i]] = i;

        string st = "";
        unordered_set<char> inStack;

        for (int i = 0; i < s.size(); i++) {
            if (inStack.count(s[i])) continue; 

            while (!st.empty() && s[i] < st.back() && last[st.back()] > i) {
                inStack.erase(st.back());
                st.pop_back();
            }

            st += s[i];
            inStack.insert(s[i]);
        }
        return st;
    }
};
