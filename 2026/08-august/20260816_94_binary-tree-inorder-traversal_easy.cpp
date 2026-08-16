/*
 * Problem 94: Binary Tree Inorder Traversal
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Approach:
 * The key insight behind inorder traversal (Left-Root-Right) is that it processes nodes in ascending order of their physical left-to-right positions, which naturally yields sorted keys in binary search trees. This implementation uses a recursive divide-and-conquer depth-first search, breaking the problem into independent subproblems where left and right subtrees are traversed to yield local result arrays. These intermediate arrays are then physically combined with the current root's value at each frame of recursion. Although conceptually elegant, this delegation pattern incurs copying overhead at each merge step compared to passing a single vector reference accumulator.
 *
 * Time Complexity: O(N log N) on average — Driven by the vector concatenation operations (`vector::insert`) performed at each recursive step. In a balanced tree, copying subtree results of size K yields a recurrence relation of T(N) = 2T(N/2) + O(N) which resolves to O(N log N) time; in a completely skewed tree, this degrades to O(N^2) time.
 * Space Complexity: O(N) — Dominated by the call stack depth which scales to O(N) in skewed trees, along with the temporary vector instances created and returned up the call stack during traversal reconstruction.
 *
 * Runtime: 3 ms | Memory: 12.6 MB
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
