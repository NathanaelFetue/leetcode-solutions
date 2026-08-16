/*
 * Problem 94: Binary Tree Inorder Traversal
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Approach:
 * The key insight to inorder traversal is preserving the Left-Root-Right visitation sequence, which can be modeled as a divide-and-conquer recursive decomposition. By treating the left and right subtrees as independent subproblems, we can compute their traversals and merge them around the current root's value. This functional recursion style avoids global state or shared reference parameters by constructing and returning intermediate vectors up the call stack. While this design introduces copying overhead, it highlights the structural decomposition of tree problems into sub-problems.
 *
 * Time Complexity: O(N^2) — driven by the repeated vector copying and concatenation operations at each level of recursion on highly skewed trees, which degrades from the optimal linear time to quadratic; for balanced trees, this overhead is O(N log N).
 * Space Complexity: O(N^2) — driven by the creation of intermediate vector copies across O(H) call stack frames (where H is the tree height), resulting in quadratic space in the worst case (skewed tree) and O(N log N) on average.
 *
 * Runtime: 0 ms | Memory: 12.4 MB
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == nullptr) return res;

        vector<int> left_res = inorderTraversal(root->left);
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.push_back(root->val);
        vector<int> right_res = inorderTraversal(root->right);
        res.insert(res.end(), right_res.begin(), right_res.end());

        return res;
    }
};
