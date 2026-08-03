/*
 * Problem #235: Lowest Common Ancestor of a Binary Search Tree (Medium)
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 *
 * Approach: For each target node (p and q), perform a BST search that records the
 * full path from root to that node. Then compare the two ancestor paths in order
 * from root, and return the last node where both paths share the same ancestor.
 *
 * Time Complexity: O(H) where H is the height of the BST. Each search traverses
 * at most one root-to-leaf path, and the comparison loop runs at most O(H) steps.
 * In the worst case (skewed tree), H = O(N).
 *
 * Space Complexity: O(H) for the two ancestor path vectors stored during the two
 * BST searches, where H is the height of the tree.
 *
 * Runtime: 15 ms | Memory: 23.7 MB
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> search_val(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return {};
        if (root->val == p->val)
            return {root};
        vector<TreeNode*> res;
        if (root->val > p->val) res = search_val(root->left, p);
        else res = search_val(root->right, p);

        if (!res.empty()) res.insert(res.begin(), root);

        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode* > ancestor_p = search_val(root , p);
        vector<TreeNode* > ancestor_q = search_val(root , q);
        int n = min(ancestor_p.size(), ancestor_q.size());
        TreeNode* ans = nullptr;

        for (int i = 0; i < n; i++) {
            if (ancestor_p[i] == ancestor_q[i])
                ans = ancestor_p[i];
            else
                break;
        }

        return ans;
    }
};
