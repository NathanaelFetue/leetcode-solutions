/*
 * 1925. Count Square Sum Triples - Easy
 * https://leetcode.com/problems/count-square-sum-triples/
 *
 * Approach: Hash Set Lookup
 * First, precompute all perfect squares up to n^2 and store them in an unordered_set.
 * Then iterate over all pairs (a, b) and check if a^2 + b^2 is also a perfect square,
 * counting each valid triple (a, b, c) where c <= n.
 *
 * Time Complexity: O(n^2) - double loop over all pairs (a, b) from 1 to n,
 * with O(1) average-case lookup in the hash set.
 *
 * Space Complexity: O(n) - the hash set stores at most n perfect squares.
 *
 * Runtime: 23 ms
 * Memory: 9.1 MB
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
