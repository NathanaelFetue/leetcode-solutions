/*
 * Problem 1925: Count Square Sum Triples (Easy)
 * https://leetcode.com/problems/count-square-sum-triples/
 *
 * Approach: Hash Set Lookup
 * First, precompute all perfect squares up to n^2 and store them in an unordered_set.
 * Then iterate over all pairs (a, b) where 1 <= a, b <= n, and check if a^2 + b^2
 * exists in the set and its square root c satisfies c <= n (implicitly guaranteed since
 * a^2 + b^2 <= 2*n^2, but c = sqrt(a^2+b^2) must itself be a perfect square in the set).
 *
 * Time Complexity: O(n^2) - double loop over all pairs (a, b), with O(1) hash set lookup.
 * Space Complexity: O(n) - storing at most n perfect squares in the hash set.
 *
 * Runtime: 30 ms
 * Memory: 9 MB
 */

class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> sq;
        for (int i = 1; i <= n; i++) sq.insert(i * i);

        int result = 0;
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= n; b++)
                if (sq.count(a*a + b*b)) result++;

        return result;
    }
};
