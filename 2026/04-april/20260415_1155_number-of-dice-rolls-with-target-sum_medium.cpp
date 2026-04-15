/*
 * Problem #1155 - Number of Dice Rolls With Target Sum (Medium)
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 *
 * Approach: Inclusion-Exclusion with Combinatorics
 * The problem reduces to counting the number of ways to write `target` as an ordered sum of `n` integers each in [1, k].
 * Using stars-and-bars, the unconstrained count is C(target-1, n-1), then inclusion-exclusion subtracts cases where one or more dice exceed k (i.e., at least one die contributes > k, modeled by substituting x_i' = x_i - k).
 * Precomputed factorials and modular inverses via Fermat's little theorem enable O(1) binomial coefficient queries.
 *
 * Time Complexity: O(n + N) where N = 1005 for precomputation and O(n) for the inclusion-exclusion loop.
 * Space Complexity: O(N) for the precomputed factorial and inverse factorial arrays.
 *
 * Runtime: 0 ms
 * Memory: 7.9 MB
 */

const int MOD = 1e9+7;
const int N = 1e3+5;

long long fact[N], invfact[N];

long long modpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precom(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    invfact[N-1] = modpow(fact[N-1], MOD-2);

    for(int i = N-2; i >= 0; i--)
        invfact[i] = ((i+1) * invfact[i+1]) % MOD;
}

long long C(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > 1LL*n*k) return 0;
        precom();
        long long ans = C(target-1, n-1);

        for(int i = 1; i <= n; i++){
            int news = target - i*k;
            if(news < n) break;

            long long cur = C(n, i) * C(news-1, n-1) % MOD;

            if(i & 1) ans = (ans - cur + MOD) % MOD;
            else ans = (ans + cur) % MOD;
        }

        return ans;
    }
};
