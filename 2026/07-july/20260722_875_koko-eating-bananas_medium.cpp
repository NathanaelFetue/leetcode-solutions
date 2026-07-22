/*
 * Problem #875: Koko Eating Bananas (Medium)
 * https://leetcode.com/problems/koko-eating-bananas/
 *
 * Approach: Binary Search on Answer
 * The minimum viable eating speed lies in the range [1, max(piles)]. Binary search
 * is applied over this range to find the smallest speed k such that Koko can finish
 * all bananas within h hours. For each candidate speed, ceiling division computes
 * the hours needed per pile, and the total is compared against h.
 *
 * Time Complexity: O(n log m)
 *   - n = number of piles, m = max pile size
 *   - Binary search runs O(log m) iterations, each scanning all n piles
 *
 * Space Complexity: O(1)
 *   - Only a constant number of variables are used beyond the input
 *
 * Runtime : 4 ms
 * Memory  : 23.1 MB
 */

class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int p : piles)
            hours += (p + k - 1) / k;
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
