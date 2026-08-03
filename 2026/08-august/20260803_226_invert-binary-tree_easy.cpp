/*
 * Problem 226: Invert Binary Tree (Easy)
 * https://leetcode.com/problems/invert-binary-tree/
 *
 * Approach: Recursive DFS (Pre-order Traversal)
 * At each node, swap the left and right children first, then recursively
 * invert the left and right subtrees. The base case returns null nodes immediately.
 * This pre-order swap ensures every node's children are mirrored throughout the tree.
 *
 * Time Complexity: O(n) - every node in the tree is visited exactly once.
 * Space Complexity: O(h) - recursion stack depth equals the height h of the tree;
 *                   O(log n) average for balanced trees, O(n) worst case for skewed trees.
 *
 * Runtime : 0 ms
 * Memory  : 12.6 MB
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        root -> left = invertTree(root -> left);
        root -> right = invertTree(root -> right);

        return root;
    }
};
