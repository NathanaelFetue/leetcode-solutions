/*
 * Problem #98: Validate Binary Search Tree (Medium)
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Approach: Recursive validation with min/max bounds propagation.
 * Each node is validated against a valid range (min, max). When recursing left,
 * the current node's value becomes the new upper bound; when recursing right,
 * it becomes the new lower bound. LONG_MIN and LONG_MAX are used as initial
 * bounds to safely handle integer edge cases (e.g., INT_MIN, INT_MAX node values).
 *
 * Time Complexity:  O(n) - every node is visited exactly once.
 * Space Complexity: O(h) - recursive call stack depth equals tree height h;
 *                   O(log n) for balanced trees, O(n) worst case (skewed tree).
 *
 * Runtime : 0 ms
 * Memory  : 21.9 MB
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool validate(TreeNode* node, long min, long max) {
        if (node == nullptr) return true;
        if (node->val <= min || node->val >= max) return false;
        return validate(node->left, min, node->val)
            && validate(node->right, node->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
