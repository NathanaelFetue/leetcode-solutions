/*
 * Problem 3069: Distribute Elements Into Two Arrays I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
 *
 * Approach:
 * The key insight is that we can directly simulate the partitioning rules in a single linear pass by leveraging dynamic arrays with O(1) tail access. We initialize two vectors, placing the first two elements of the input as their respective seeds. For each subsequent element, we greedily append it to the array whose last element is strictly greater, resolving ties and smaller-than conditions by defaulting to the second array. Finally, we perform an in-place concatenation of the second array onto the first, preserving the stable relative ordering of elements.
 *
 * Time Complexity: O(N) — One linear scan is performed to distribute the elements based on O(1) tail comparisons, followed by a linear-time vector concatenation of the two partitioned arrays.
 * Space Complexity: O(N) — We allocate two auxiliary vectors, arr1 and arr2, which collectively store all N elements of the input array.
 *
 * Runtime: 0 ms | Memory: 23.8 MB
 */

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
