/*
 * Problem 32: Longest Valid Parentheses
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/longest-valid-parentheses/
 *
 * Approach:
 * The key insight is that a stack can maintain the indices of unmatched parentheses to dynamically compute the length of valid substrings. By seeding the stack with an initial baseline index of -1, we can handle edge cases where a valid parenthesis string starts from the very beginning of the input seamlessly. When we encounter a closing parenthesis, we pop the top element representing the matched opening parenthesis or the boundary of the last invalid character. If the stack becomes empty, the current index serves as a new base reference, otherwise the length of the current valid substring is computed as the distance from the current index to the new top of the stack. This stack-based linear scan approach ensures we correctly capture nested and adjacent valid segments in a single pass.
 *
 * Time Complexity: O(n) - We iterate through the string of length n exactly once, performing constant time stack operations for each character.
 * Space Complexity: O(n) - In the worst-case scenario, all characters are opening parentheses and are stored in the stack.
 *
 * Runtime: 2 ms | Memory: 12.3 MB
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
