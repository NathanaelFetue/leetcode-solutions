/*
 * Problem #133 - Clone Graph (Medium)
 * https://leetcode.com/problems/clone-graph/
 *
 * Approach: Iterative DFS using an explicit stack and a hash map.
 * The hash map tracks original-to-clone node mappings to avoid duplicate cloning.
 * For each node popped from the stack, unvisited neighbors are cloned and pushed,
 * and the cloned neighbor is appended to the current clone's neighbor list.
 *
 * Time Complexity : O(V + E) - every node (V) and edge (E) is visited exactly once.
 * Space Complexity: O(V) - hash map stores one entry per node; stack holds at most V nodes.
 *
 * Runtime : 0 ms
 * Memory  : 11.9 MB
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        stack<Node*> st;

        mp[node] = new Node(node->val);
        st.push(node);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            for (Node* neigh : curr->neighbors) {
                if (mp.find(neigh) == mp.end()) {
                    mp[neigh] = new Node(neigh->val);
                    st.push(neigh);
                }
                mp[curr]->neighbors.push_back(mp[neigh]);
            }
        }

        return mp[node];
    }
};
