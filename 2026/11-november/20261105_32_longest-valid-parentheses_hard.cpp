/*
 * Problem 32: Longest Valid Parentheses
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/longest-valid-parentheses/
 *
 * Approach:
 * The key insight is using a stack to store indices rather than characters, serving as boundary markers for valid substrings. By initializing the stack with a dummy boundary of -1, we can compute the length of any valid substring as the distance between the current index and the element at the top of the stack. When an open parenthesis is met, its index is pushed onto the stack. Upon encountering a close parenthesis, we pop the stack; if it becomes empty, the current close parenthesis has no matching open parenthesis and becomes the new boundary marker. Otherwise, the length of the valid substring ending at the current position is calculated as the difference between the current index and the stack top index.
 *
 * Time Complexity: O(N) - Single pass over the string of length N with constant-time stack operations per character.
 * Space Complexity: O(N) - The stack stores at most N indices in the worst-case scenario of all open parentheses.
 *
 * Runtime: 4 ms | Memory: 12.4 MB
 */

class Solution {
public:
    int longestValidParentheses(auto& s) {
        int res = 0;
        vector<int> stack = {-1};
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                stack.pop_back();
                
                if (stack.empty())
                    stack.push_back(i);
                else
                    res = max(res, i - stack.back());
            }
        }
        
        return res;
    }
};
