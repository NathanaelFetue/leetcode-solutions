/*
 * Problem #104 - Maximum Depth of Binary Tree (Easy)
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Approach: Recursive Depth-First Search (DFS)
 * The solution uses recursion to traverse the binary tree. At each node, it checks
 * whether the left and/or right children exist and recursively computes the depth
 * of each subtree, returning 1 plus the maximum of the two subtree depths.
 *
 * Time Complexity: O(n) - Every node in the tree is visited exactly once,
 * where n is the total number of nodes.
 *
 * Space Complexity: O(h) - The call stack depth equals the height h of the tree.
 * In the worst case (skewed tree) this is O(n); for a balanced tree it is O(log n).
 *
 * Runtime: 0 ms | Memory: 22.1 MB
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
        if(root == nullptr) return 0;
        if(root != nullptr){
            if(root -> left == nullptr && root-> right == nullptr) return 1;
            if(root -> left == nullptr && root -> right != nullptr) return 1 + maxDepth(root -> right);
            if(root -> left != nullptr && root -> right == nullptr) return 1 + maxDepth(root -> left);
            return (1 + max( maxDepth(root -> left) , maxDepth(root -> right)));
        }
        return 1;
    }
};
