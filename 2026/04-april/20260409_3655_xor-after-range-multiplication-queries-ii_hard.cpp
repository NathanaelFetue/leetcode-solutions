/*
 * Problem #3655: XOR After Range Multiplication Queries II (Hard)
 * URL: https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/
 *
 * Approach: Square-root decomposition (sqrt decomposition) on query step sizes.
 * Queries with step k > sqrt(n) are applied directly (sparse updates, at most sqrt(n) indices touched).
 * Queries with step k <= sqrt(n) are batched by k and applied using a difference-array-like technique
 * with modular inverses to propagate prefix products along each stride k efficiently.
 * After computing total multipliers per index (mod 1e9+7), XOR all final values.
 *
 * Time Complexity: O((n + Q) * sqrt(n))
 *   - Large-step queries: O(n/k) per query, O(Q * sqrt(n)) total
 *   - Small-step queries: O(n) per stride k, O(n * sqrt(n)) total for all strides
 *
 * Space Complexity: O(n + Q + sqrt(n))
 *   - O(n) for total_mult and diff arrays
 *   - O(Q) for bucketed queries grouped by step size
 *   - O(sqrt(n)) buckets
 *
 * Runtime: 415 ms | Memory: 246 MB
 */

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n);
        vector<int> total_mult(n, 1);
        long long MOD = 1e9 + 7;

        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        auto modInverse = [&](long long n_val) {
            return power(n_val, MOD - 2);
        };

        vector<vector<vector<int>>> q_by_k(B + 1);
        
        vector<vector<int>> bravexuneth = queries;

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    total_mult[i] = (1LL * total_mult[i] * v) % MOD;
                }
            } else {
                q_by_k[k].push_back({l, r, v});
            }
        }

        vector<int> diff(n);
        for (int k = 1; k <= B; k++) {
            if (q_by_k[k].empty()) continue;
            fill(diff.begin(), diff.end(), 1);
            for (auto& q : q_by_k[k]) {
                int l = q[0], r = q[1], v = q[2];
                diff[l] = (1LL * diff[l] * v) % MOD;
                int num_steps = (r - l) / k;
                int end_idx = l + num_steps * k;
                if (end_idx + k < n) {
                    diff[end_idx + k] = (1LL * diff[end_idx + k] * modInverse(v)) % MOD;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (1LL * diff[i] * diff[i - k]) % MOD;
                }
                total_mult[i] = (1LL * total_mult[i] * diff[i]) % MOD;
            }
        }

        int final_xor = 0;
        for (int i = 0; i < n; i++) {
            long long final_val = (1LL * nums[i] * total_mult[i]) % MOD;
            final_xor ^= final_val;
        }

        return final_xor;
    }
};
