/*
 * Problem #2657 - Find the Prefix Common Array of Two Arrays (Medium)
 * https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 *
 * Approach: Single-pass frequency counting using a hash map.
 * For each index i, we insert A[i] and B[i] into a shared frequency map.
 * Whenever an element's frequency reaches 2, it means it has appeared in both A and B up to index i, so we increment a running common count.
 *
 * Time Complexity: O(n) - single pass through both arrays of size n.
 * Space Complexity: O(n) - hash map stores at most 2n elements (all values from A and B).
 *
 * Runtime: 16 ms
 * Memory: 88 MB
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        unordered_map<int, int> freq; // fréquence : combien de fois vu (A+B)
        int common = 0;

        for (int i = 0; i < n; i++) {
            // Ajouter A[i]
            freq[A[i]]++;
            if (freq[A[i]] == 2) common++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) common++;

            res[i] = common;
        }
        return res;
    }
};
