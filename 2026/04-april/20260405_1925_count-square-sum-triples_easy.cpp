/*
 * Problem 1925: Count Square Sum Triples (Easy)
 * https://leetcode.com/problems/count-square-sum-triples/
 *
 * Approach: Hash Set Lookup
 * First, precompute all perfect squares up to n^2 and store them in an unordered set.
 * Then iterate over all pairs (a, b) where 1 <= a, b <= n, checking if a^2 + b^2
 * exists in the set and is also a perfect square c^2 where c <= n.
 *
 * Time Complexity: O(n^2) — double loop over all pairs (a, b) with O(1) set lookup.
 * Space Complexity: O(n) — unordered set stores at most n perfect squares.
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
