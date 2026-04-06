/*
 * Problem 1022: Sum of Root To Leaf Binary Numbers (Easy)
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 *
 * Approach: Depth-First Search (DFS) with string accumulation.
 * Perform a DFS traversal of the binary tree, building a binary string representation
 * of each root-to-leaf path. At each leaf node, convert the accumulated binary string
 * to its decimal integer value using base-2 conversion, then sum all results.
 *
 * Time Complexity: O(N * L) where N is the number of nodes and L is the average
 * path length (tree height), due to string concatenation at each node during DFS.
 *
 * Space Complexity: O(N * L) for storing all root-to-leaf path strings in the
 * paths vector, plus O(H) recursion stack space where H is the tree height.
 *
 * Runtime: 2 ms | Memory: 21.3 MB
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
    vector <string> paths;

    void dfs(TreeNode* root , string current) {
        if (!root) return;
        current += to_string(root ->val);
        if (!root -> left && !root -> right) {
            paths.push_back(current);
            return;
        }
        dfs(root ->left, current);
        dfs(root ->right , current);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        dfs(root, "");
        for (string path : paths) {
            sum+= stoi(path,nullptr,2);
        }
        return sum;
        
    }
};
