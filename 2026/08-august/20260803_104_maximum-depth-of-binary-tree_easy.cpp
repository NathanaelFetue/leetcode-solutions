/*
 * Problem #104 - Maximum Depth of Binary Tree (Easy)
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Approach: Recursive DFS (Depth-First Search)
 * The solution uses a recursive post-order traversal to compute the maximum depth.
 * At each node, it recursively finds the maximum depth of the left and right subtrees,
 * then returns 1 plus the greater of the two depths. The base case returns 0 for null nodes.
 *
 * Time Complexity: O(n) - every node in the tree is visited exactly once.
 * Space Complexity: O(h) - where h is the height of the tree, due to the recursive call
 * stack. In the worst case (skewed tree) this is O(n); for a balanced tree it is O(log n).
 *
 * Runtime: 0 ms
 * Memory: 22.1 MB
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
