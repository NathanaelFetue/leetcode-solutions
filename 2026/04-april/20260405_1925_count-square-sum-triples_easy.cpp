/*
 * Problem 1925: Count Square Sum Triples (Easy)
 * https://leetcode.com/problems/count-square-sum-triples/
 *
 * Approach: Precompute all perfect squares from 1 to n into a vector and store
 * them in an unordered_set for O(1) lookups. Iterate over all pairs (a, b) and
 * check if a^2 + b^2 exists in the set, counting valid triples (a, b, c).
 *
 * Time Complexity: O(n^2) - double loop over all pairs (i, j) from 1 to n,
 * with O(1) hash set lookup per pair.
 *
 * Space Complexity: O(n) - storing n precomputed squares in both a vector
 * and an unordered_set.
 *
 * Runtime: 35 ms
 * Memory: 9.8 MB
 */

class Solution {
public:
    int countTriples(int n) {
        vector <int> squares(n);
        for  (int i =0; i < n; i++) {
            squares[i] = (i+1)*(i+1);
        }
        int result =0;
        unordered_set <int> sq(squares.begin() , squares.end());
        for (int i=0; i< n; i++) {
            for (int j = 1; j<n ; j++){
                int c2 = squares[i] + squares[j];
                if (sq.count(c2)) {
                    result +=1;
                }
            }
        }
        return result;
    }
};
