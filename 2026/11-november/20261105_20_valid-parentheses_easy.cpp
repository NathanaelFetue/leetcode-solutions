/*
 * Problem 20: Valid Parentheses
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/valid-parentheses/
 *
 * Approach:
 * The key insight is that nested parenthesis matching strictly follows a Last-In, First-Out (LIFO) order, as the most recently opened bracket must be the first one to be closed. Using a stack alongside a hash map for closing-to-opening bracket lookup, we push every opening bracket onto the stack. When encountering a closing bracket, it must match the stack's top element; a mismatch or an empty stack immediately invalidates the string. The string is valid if and only if the stack is completely empty after processing all characters.
 *
 * Time Complexity: O(n) - A single traversal of the string of length n, where each character involves O(1) stack operations and map lookups.
 * Space Complexity: O(n) - In the worst case (e.g., all opening brackets), the stack will store up to n characters.
 *
 * Runtime: 0 ms | Memory: 8.8 MB
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();        
    }
};
