/*
 * Problem 22: Generate Parentheses
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/generate-parentheses/
 *
 * Approach:
 * The key insight is that valid parentheses strings can be constructed incrementally by tracking the remaining counts of open and close brackets, ensuring at any point that the number of close brackets used does not exceed the open brackets. We use a Depth-First Search (DFS) backtracking approach to explore valid branching paths, strictly adding an open parenthesis when available and a close parenthesis only when it maintains prefix validity. By initializing the recursion with the first mandatory '(' and pre-decrementing n, we optimize the base cases and avoid redundant checks. This recursive exploration systematically builds every well-formed combination without generating invalid sequences.
 *
 * Time Complexity: O(4^n / sqrt(n)) - The number of valid parentheses combinations is given by the nth Catalan number, which asymptotically bounds the total operations.
 * Space Complexity: O(n) - The recursion stack and string builder consume space proportional to the maximum depth of 2n.
 *
 * Runtime: 5 ms | Memory: 13.9 MB
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n-- == 1) return {"()"};

        vector<string> res;
        auto dfs = [&](auto& self, int O, int C, string s) -> void {
            if (O == 0 && C == 0) {
                res.push_back(s + ")");
                return;
            }

            if (O > 0)
                self(self, O - 1, C, s + "(");

            if (C >= O)
                self(self, O, C - 1, s + ")");
        };

        dfs(dfs, n, n, "(");

        return res;
    }
};
