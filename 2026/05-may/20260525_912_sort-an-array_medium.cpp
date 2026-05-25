/*
 * Problem #912: Sort an Array
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sort-an-array/
 *
 * Approach: Merge Sort (Top-Down Recursive)
 * The array is recursively split into two halves until each sub-array has at most one element.
 * Each pair of sorted halves is merged back together using a two-pointer technique, producing a fully sorted array.
 *
 * Time Complexity: O(n log n) — the array is divided log n times and each merge pass processes n elements.
 * Space Complexity: O(n log n) — new vectors are allocated at each level of recursion; O(log n) recursion depth with O(n) temporary storage per level.
 *
 * Runtime: 1484 ms
 * Memory: 516.3 MB
 */

class Solution {
public:
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) res.push_back(a[i++]);
            else               res.push_back(b[j++]);
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back(b[j++]);

        return res;
    }

    vector<int> sortArray(vector<int> nums) {
        if (nums.size() <= 1) return nums;
        int mid = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        left  = sortArray(left);
        right = sortArray(right);

        return merge(left, right);
    }
};
