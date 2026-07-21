/*
 * Problem #74 - Search a 2D Matrix (Medium)
 * https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Approach: Parallel Binary Search using C++ threads
 * Each row of the matrix is searched concurrently using a dedicated thread.
 * Each thread performs a binary search on its assigned row, and an atomic boolean
 * flag is used to signal early termination once the target is found.
 *
 * Time Complexity: O((m * log n) / m) = O(log n) in ideal parallel execution,
 * where m is the number of rows and n is the number of columns. In practice,
 * thread overhead may dominate for small inputs.
 *
 * Space Complexity: O(m) for spawning m threads, one per row.
 *
 * Runtime: 176 ms
 * Memory: 21 MB
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
