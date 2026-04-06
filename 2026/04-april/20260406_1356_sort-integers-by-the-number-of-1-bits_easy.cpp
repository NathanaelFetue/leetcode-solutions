/*
 * Problem 1356: Sort Integers by The Number of 1 Bits
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 *
 * Approach: For each integer, compute its popcount (number of set bits) using the
 * GCC built-in __builtin_popcount, then store (popcount, value) pairs in a vector.
 * Sorting the pairs lexicographically naturally sorts first by bit count, then by
 * value for ties, before extracting the sorted values into the result.
 *
 * Time Complexity: O(n log n) — dominated by sorting n pairs; popcount per element
 * is O(1) with the hardware/built-in instruction.
 *
 * Space Complexity: O(n) — extra vector of pairs of size n used for sorting.
 *
 * Runtime: 0 ms
 * Memory: 14.7 MB
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector <pair<int , int>> res;
        for (int num : arr){
            int ones = __builtin_popcount(num);
            res.push_back({ones , num});
        }
        sort(res.begin(), res.end());
        vector<int> sortedNums;
        for( auto& p: res) sortedNums.push_back(p.second);

        return sortedNums;
    }
};
