/*
 * Problem #74 - Search a 2D Matrix (Medium)
 * https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Approach: Binary Search on Flattened Matrix
 * The m x n matrix is treated as a single sorted array of m*n elements.
 * For any virtual index mid, the corresponding 2D cell is matrix[mid/n][mid%n],
 * enabling a standard binary search over the entire matrix in one pass.
 *
 * Time Complexity: O(log(m*n)) - binary search over m*n elements
 * Space Complexity: O(1) - only a constant number of variables are used
 *
 * Runtime: 0 ms
 * Memory: 13.3 MB
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n - 1;

        while(left <= right){
            int mid = left + (right-left)/2;
            int value = matrix[mid/n][mid%n];

            if(value == target)
                return true;
            if(value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
