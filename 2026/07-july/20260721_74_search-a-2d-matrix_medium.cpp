/*
 * Problem 74: Search a 2D Matrix
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Approach: Parallel Binary Search using C++ std::thread and std::atomic.
 * Each row of the matrix is searched concurrently using a dedicated thread that
 * performs a binary search on its row. An atomic boolean flag short-circuits
 * remaining threads once the target is found, and all threads are joined before
 * returning the result.
 *
 * Time Complexity: O((m * log n) / m) = O(log n) theoretical with perfect parallelism,
 * where m is the number of rows and n is the number of columns. In practice,
 * thread overhead may dominate for small inputs.
 *
 * Space Complexity: O(m) for the thread pool holding one thread per row.
 *
 * Runtime: 188 ms
 * Memory: 19.1 MB
 */

class Solution {
    atomic<bool> found = false;
public:
    void searchRow(const vector<int>& row, int target) {
        if (found.load()) return;

        if (binary_search(row.begin(), row.end(), target))
            found = true;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<thread> threads;

        for (const auto& row : matrix) {
            threads.emplace_back(
                &Solution::searchRow,
                this,
                cref(row),
                target
            );
        }

        for (auto& t : threads)
            t.join();

        return found.load();
    }
};
