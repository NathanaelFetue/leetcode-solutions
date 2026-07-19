/*
 * Problem 1081: Smallest Subsequence of Distinct Characters (Medium)
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 * Approach: Greedy stack-based algorithm with character tracking.
 * For each character, we use a monotonic stack to greedily maintain the lexicographically smallest result.
 * If the current character is smaller than the stack top and the top character appears later in the string, we pop the top and replace it, ensuring all distinct characters are still reachable.
 *
 * Key Data Structures:
 * - 'last' map: stores the last occurrence index of each character.
 * - 'inStack' set: tracks characters currently in the result stack to avoid duplicates.
 *
 * Time Complexity: O(n) - single pass to build last-occurrence map, single pass to build the result;
 *   each character is pushed and popped at most once.
 * Space Complexity: O(1) - the stack and set hold at most 26 distinct characters (bounded by alphabet size).
 *
 * Runtime: 1 ms | Memory: 9 MB
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
