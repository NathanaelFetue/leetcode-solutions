/*
 * Problem #912: Sort an Array
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sort-an-array/
 *
 * Approach: Merge Sort (Divide and Conquer)
 * The array is recursively divided into two halves until each subarray contains a single element.
 * The mergeHelper function then merges two sorted subarrays by comparing elements one by one and
 * writing the sorted result into a temporary array, which is copied back into the original array.
 *
 * Time Complexity: O(n log n)
 *   - The array is split log n times and each merge step processes n elements in total.
 *
 * Space Complexity: O(n)
 *   - A temporary array of size equal to the current subarray is allocated at each merge step;
 *     the maximum space used at any point is O(n).
 *
 * Runtime: 223 ms | Memory: 146.5 MB
 */

class Solution {
    void mergeHelper(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else                    tmp[k++] = nums[j++];
        }
        while (i <= mid)   tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];

        for (int i = 0; i < tmp.size(); i++)
            nums[left + i] = tmp[i];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        mergeHelper(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
