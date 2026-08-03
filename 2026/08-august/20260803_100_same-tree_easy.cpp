/*
 * Problem #100 - Same Tree
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/same-tree/
 *
 * Approach: Recursive DFS comparison of both trees simultaneously.
 * Base cases handle null nodes: if both are null the subtrees match, if only one is null they differ.
 * For non-null nodes, values are compared first, then recursively check left and right subtrees.
 *
 * Time Complexity: O(n) - where n is the minimum number of nodes between the two trees,
 * as we visit each node at most once.
 *
 * Space Complexity: O(h) - where h is the height of the tree due to the recursive call stack.
 * In the worst case (skewed tree) this becomes O(n); O(log n) for a balanced tree.
 *
 * Runtime: 0 ms
 * Memory: 12.9 MB
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
        if( p->val != q -> val ) return false;
        return (isSameTree(p -> left , q-> left) && isSameTree(p -> right , q-> right));

    }
};
