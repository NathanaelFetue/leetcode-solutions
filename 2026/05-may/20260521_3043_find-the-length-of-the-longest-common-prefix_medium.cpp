/*
 * Problem #3043 - Find the Length of the Longest Common Prefix (Medium)
 * URL: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 *
 * Approach: Prefix Hash Set
 * First, extract all numeric prefixes of every number in arr1 by repeatedly dividing by 10,
 * storing each intermediate value in a hash set. Then, for each number in arr2, progressively
 * trim digits from the right until a match is found in the set, tracking the longest such match.
 *
 * Time Complexity: O((M + N) * D) where M and N are the lengths of arr1 and arr2 respectively,
 * and D is the maximum number of digits in any element (at most 10 for 32-bit integers).
 *
 * Space Complexity: O(M * D) for storing all prefixes of arr1 elements in the hash set.
 *
 * Runtime: 153 ms
 * Memory: 135.6 MB
 */

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        for (int x : arr2) {
            while (x > 0) {
                if (prefixes.count(x)) {
                    int len = to_string(x).size();
                    ans = max(ans, len);
                    break;
                }
                x /= 10;
            }
        }

        return ans;
    }
};
