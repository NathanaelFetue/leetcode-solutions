/*
 * Problem 3507: Minimum Pair Removal to Sort Array I (Easy)
 * https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
 *
 * Approach: Greedy simulation with in-place array modification.
 * Repeatedly scan the array to find the adjacent pair with the minimum sum,
 * replace the pair with their sum, and remove the second element until the array is non-decreasing.
 *
 * Time Complexity: O(n^3) in the worst case — O(n) iterations for up to O(n) merge operations,
 * each requiring an O(n) scan plus O(n) erase shifting elements.
 *
 * Space Complexity: O(1) extra space — modifications are made in-place on the input vector
 * with no auxiliary data structures.
 *
 * Runtime: 4 ms
 * Memory: 26.4 MB
 */

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int nbOp = 0;
        auto isNonDecreasing = [&]() {
            for (int i = 0; i < nums.size()-1; i++)
                if (nums[i] > nums[i+1]) return false;
            return true;
        };

        while (!isNonDecreasing()) {
            int minSum = INT_MAX, idx = 0;
            for (int i = 0; i < nums.size()-1; i++) {
                if (nums[i] + nums[i+1] < minSum) {
                    minSum = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            nbOp++;
        }
        return nbOp;
    }
};
