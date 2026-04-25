/*
 * Problem #3464: Maximize the Distance Between Points on a Square
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/
 *
 * Approach: Coordinate Linearization + Binary Search with Greedy Validation
 * Points on the square boundary are mapped to a 1D linear coordinate along the perimeter
 * (total perimeter = 4*side). A binary search on the answer (minimum distance) is performed,
 * and for each candidate distance, a greedy check verifies if k points can be placed with
 * at least that spacing, wrapping around the perimeter using a doubled-window technique.
 *
 * Time Complexity: O(n log n * log(side))
 *   - Sorting takes O(n log n); binary search runs O(log(side)) iterations;
 *     each check iterates over n starting points with O(k log n) binary lookups.
 * Space Complexity: O(n) for the linearized perimeter coordinate array.
 *
 * Runtime: 55 ms | Memory: 45.1 MB
 */

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.push_back(y);
            } else if (y == side) {
                arr.push_back(side + x);
            } else if (x == side) {
                arr.push_back(side * 3LL - y);
            } else {
                arr.push_back(side * 4LL - x);
            }
        }
        sort(arr.begin(), arr.end());

        auto check = [&](long long limit) -> bool {
            for (long long start : arr) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(arr, cur + limit);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0) {
                    return true;
                }
            }
            return false;
        };

        long long lo = 1, hi = side;
        int ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
