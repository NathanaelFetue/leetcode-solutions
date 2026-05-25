/*
 * Problem #238 - Product of Array Except Self (Medium)
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Approach: Prefix and Suffix Product Arrays
 * Build a prefix product array where pref[i] holds the product of all elements to the left of index i,
 * and a suffix product array where suff[i] holds the product of all elements to the right of index i.
 * The result for each index is simply the product of its corresponding prefix and suffix values.
 *
 * Time Complexity: O(n) - three separate linear passes over the array (prefix, suffix, result).
 * Space Complexity: O(n) - three auxiliary arrays of size n (pref, suff, res) are allocated.
 *
 * Runtime: 0 ms
 * Memory: 42.3 MB
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n), res(n);

        pref[0] = 1;
        for (int i = 1; i < n; i++)
            pref[i] = pref[i-1] * nums[i-1];

        suff[n-1] = 1;
        for (int i = n-2; i >= 0; i--)
            suff[i] = suff[i+1] * nums[i+1];

        for (int i = 0; i < n; i++)
            res[i] = pref[i] * suff[i];

        return res;
    }
};
