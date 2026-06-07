/*
 * Problem 2196: Create Binary Tree From Descriptions (Medium)
 * https://leetcode.com/problems/create-binary-tree-from-descriptions/
 *
 * Approach: Hash Map + Child Tracking
 * Iterate through all descriptions, creating TreeNode objects on demand and storing
 * them in a hash map keyed by value. For each entry, link the child node to the
 * parent's left or right pointer based on the isLeft flag, and track all child
 * nodes in a separate set. The root is the node whose value never appears as a child.
 *
 * Time Complexity: O(n) - single pass to build nodes and links, plus one pass to
 * find the root, where n is the number of descriptions.
 *
 * Space Complexity: O(n) - hash map and child set each store at most n+1 unique nodes.
 *
 * Runtime: 187 ms
 * Memory: 279.2 MB
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];

            if (!nodes.count(parent)) nodes[parent] = new TreeNode(parent);
            if (!nodes.count(child))  nodes[child]  = new TreeNode(child);

            if (isLeft) nodes[parent]->left  = nodes[child];
            else        nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        for (auto& [val, node] : nodes)
            if (!children.count(val)) return node;

        return nullptr;
    }
};
