/*
 * Problem #102: Binary Tree Level Order Traversal (Medium)
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
 * Approach: Recursive DFS with level tracking.
 * A helper function performs a pre-order DFS traversal, passing the current depth
 * as a parameter. At each node, if the result vector does not yet have a subarray
 * for the current level, one is created. The node's value is then appended to the
 * subarray corresponding to its depth, naturally grouping values by level.
 *
 * Time Complexity: O(n) - every node in the tree is visited exactly once.
 * Space Complexity: O(n) - the result vector stores all n node values, and the
 * recursion call stack can reach O(h) depth where h is the tree height
 * (O(n) in the worst case for a skewed tree).
 *
 * Runtime: 0 ms
 * Memory: 17.3 MB
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
    void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;

        if (res.size() <= level)
            res.push_back({});
    
        res[level].push_back(root -> val);

        levelOrderRec(root->left, level + 1, res);
        levelOrderRec(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        levelOrderRec(root, 0, res);
        return res;

    }
};
