/*
 * Problem 3116: Kth Smallest Amount With Single Denomination Combination
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
 *
 * Approach:
 * The key insight is that while generating the k-th smallest multiple directly is difficult due to overlapping multiples among different denominations, verifying if a target value x contains at least k multiples is monotonic. This allows us to use binary search on the answer space [k, coins[0] * k]. To count the number of unique multiples of any coin up to x, we apply the Inclusion-Exclusion Principle (PIE) over all 2^N - 1 non-empty subsets of coins. By precomputing the LCM (Least Common Multiple) of each subset and capping values that exceed our binary search upper bound to prevent overflow, we can perform each binary search step in O(2^N) time.
 *
 * Time Complexity: O(N * 2^N + 2^N * log(k * min_coin)) — The precomputation phase takes O(N * 2^N) time to compute the LCMs for all subsets of the N coins. The binary search takes O(log(k * min_coin)) iterations, where each iteration evaluates the Inclusion-Exclusion formula across the 2^N precomputed subsets.
 *
 * Space Complexity: O(2^N) — We allocate two auxiliary vectors of size 2^N to store the LCMs and bit counts for all possible subsets of coin combinations.
 *
 * Runtime: 11 ms | Memory: 21.9 MB
 */

class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int m = (1 << n);
        sort(coins.begin(), coins.end());
        vector<int> bit_count(m);
        vector<ll> lcm(m);
        ll l = k, r = 1ll * coins[0] * k + 1;

        for (int mask = 1; mask < m; mask++) {
            ll cur_lcm = 1;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    ll tmp = cur_lcm / gcd(cur_lcm, coins[i]);
                    if (tmp <= r / coins[i]) {
                        cur_lcm = tmp * coins[i];
                    } else {
                        cur_lcm = r + 1;
                        break;
                    }
                    bit_count[mask]++;
                }
            }
            lcm[mask] = cur_lcm;
        }

        auto get = [&](ll x) -> ll {
            ll count = 0;
            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x) {
                    continue;
                }
                if (bit_count[mask] & 1) {
                    count += x / lcm[mask];
                } else {
                    count -= x / lcm[mask];
                }
            }
            return count;
        };

        while (l < r) {
            ll x = (l + r) >> 1;
            if (get(x) >= k) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        return l;
    }
};
