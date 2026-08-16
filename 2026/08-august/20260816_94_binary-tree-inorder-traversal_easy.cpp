/*
 * Problem 94: Binary Tree Inorder Traversal
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Approach:
 * The key insight behind inorder traversal is leveraging the call stack to systematically visit nodes in a left-to-right projected order. By utilizing a recursive depth-first search, we can implicitly suspend execution at a parent node while we exhaustively process its entire left subtree. This guarantees that a node is appended to the result only after all of its left descendants have been visited, and immediately before traversing its right subtree. The recursive base case naturally handles leaf boundaries by returning when a null pointer is encountered, ensuring correctness across arbitrary tree topologies.
 *
 * Time Complexity: O(N) — Every node in the binary tree is visited exactly once during the recursive depth-first traversal, where N is the total number of nodes.
 * Space Complexity: O(H) — The auxiliary space is determined by the recursion stack, which is proportional to the height of the tree H (bounded by O(N) in the worst-case skewed tree and O(log N) in a balanced tree).
 *
 * Runtime: 0 ms | Memory: 10.8 MB
 */

class Solution {
private:
    void helper(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        
        helper(root->left, res);   // Gauche
        res.push_back(root->val);  // Racine
        helper(root->right, res);  // Droite
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};
