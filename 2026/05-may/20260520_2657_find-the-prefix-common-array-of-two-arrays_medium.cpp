/*
 * Problem #2657: Find the Prefix Common Array of Two Arrays (Medium)
 * https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 *
 * Approach: Frequency Map with Running Count
 * Iterate through both arrays simultaneously, inserting each element from A[i] and B[i]
 * into a shared frequency map. Whenever an element's frequency reaches 2, it means that
 * element has appeared in both arrays up to index i, so we increment a running common count.
 * The result at each index is simply the current value of the common counter.
 *
 * Time Complexity: O(n) - single pass through both arrays of size n.
 * Space Complexity: O(n) - frequency map stores at most n distinct elements.
 *
 * Runtime: 2 ms
 * Memory: 88 MB
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        unordered_map<int, int> freq;
        int common = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) common++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) common++;

            res[i] = common;
        }
        return res;
    }
};
