/*
 * Problem #3093: Longest Common Suffix Queries (Hard)
 * URL: https://leetcode.com/problems/longest-common-suffix-queries/
 *
 * Approach: Reverse Trie with Greedy Best-Index Caching
 * Each word in wordsContainer is reversed and inserted into a trie, so common suffixes
 * become common prefixes navigable by the trie. Each trie node caches the index of the
 * shortest (tie-broken by index) wordsContainer word whose reversed form passes through it.
 * For each query, reverse it and traverse the trie as far as possible; the cached index
 * at the deepest reachable node gives the answer in O(L) per query.
 *
 * Time Complexity: O(N*L + Q*L) where N = |wordsContainer|, Q = |wordsQuery|,
 * and L = max word length. Each insertion and query traverses at most L characters.
 *
 * Space Complexity: O(N*L * 26) in the worst case for the trie node array with
 * 26 children pointers per node.
 *
 * Runtime: 399 ms | Memory: 409.6 MB
 */

class Solution {
    struct TrieNode {
        int children[26];
        int bestIdx; // index du meilleur mot dans wordsContainer
        TrieNode() : bestIdx(-1) {
            fill(children, children + 26, -1);
        }
    };

    vector<TrieNode> trie;

    void insert(const string& s, int idx, vector<string>& container) {
        int node = 0;
        // Mettre à jour la racine
        int& best = trie[0].bestIdx;
        if (best == -1 || container[idx].size() < container[best].size())
            best = idx;

        for (char c : s) {
            int ch = c - 'a';
            if (trie[node].children[ch] == -1) {
                trie[node].children[ch] = trie.size();
                trie.push_back(TrieNode());
            }
            node = trie[node].children[ch];

            int& b = trie[node].bestIdx;
            if (b == -1 || container[idx].size() < container[b].size())
                b = idx;
        }
    }

    int query(const string& s) {
        int node = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (trie[node].children[ch] == -1) break;
            node = trie[node].children[ch];
        }
        return trie[node].bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode());

        // Insérer tous les strings inversés
        for (int i = 0; i < wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(rev, i, wordsContainer);
        }

        // Répondre aux queries
        vector<int> ans;
        for (string& q : wordsQuery) {
            string rev = q;
            reverse(rev.begin(), rev.end());
            ans.push_back(query(rev));
        }
        return ans;
    }
};
