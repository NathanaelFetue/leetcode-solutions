/*
 * Problem #1925: Count Square Sum Triples (Easy)
 * URL: https://leetcode.com/problems/count-square-sum-triples/
 *
 * Approach: Precompute all perfect squares from 1 to n and store them in an
 * unordered_set for O(1) lookup. Iterate over all pairs (a, b) where a and b
 * are in range [1, n], compute a² + b², and check if the result exists in the
 * set to count valid triples (a, b, c) where a² + b² = c² and c <= n.
 *
 * Time Complexity: O(n²) - double nested loop over all pairs (a, b) from 1 to n,
 * with O(1) hash set lookup per pair.
 *
 * Space Complexity: O(n) - storing n precomputed squares in both the vector and
 * the unordered_set.
 *
 * Runtime: 33 ms | Memory: 10 MB
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
