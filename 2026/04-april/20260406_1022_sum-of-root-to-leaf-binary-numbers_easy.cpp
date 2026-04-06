/*
 * Problem 1022: Sum of Root To Leaf Binary Numbers
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 *
 * Approach: Depth-First Search (DFS) with string path accumulation.
 * Traverse the binary tree using DFS, building a binary string for each root-to-leaf path.
 * Once a leaf is reached, the binary string is stored and later converted to its decimal value using base-2 conversion, and all values are summed.
 *
 * Time Complexity: O(N * L) where N is the number of nodes and L is the average path length (depth),
 * due to string concatenation at each node and base-2 conversion for each leaf path.
 *
 * Space Complexity: O(N * L) for storing all root-to-leaf path strings in the paths vector,
 * plus O(H) recursive call stack space where H is the height of the tree.
 *
 * Runtime: 0 ms
 * Memory: 21.2 MB
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
