/*
 * Problem #20: Valid Parentheses (Easy)
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Approach: Stack-based matching with a hash map.
 * For each character, if it is an opening bracket, push it onto the stack.
 * If it is a closing bracket, verify it matches the top of the stack using the map; if not, return false. Return true only if the stack is empty at the end.
 *
 * Time Complexity: O(n) - single pass through the string of length n.
 * Space Complexity: O(n) - stack can hold at most n/2 opening brackets in the worst case.
 *
 * Runtime: 1 ms
 * Memory: 8.9 MB
 */

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;

        unordered_map<char, char> mp{
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        stack<char> st;
        for (char c : s) {
            if (mp.contains(c)) {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if (mp[st.top()] != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
