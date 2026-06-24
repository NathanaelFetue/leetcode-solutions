/*
 * Problem #3700 - Number of ZigZag Arrays II (Hard)
 * https://leetcode.com/problems/number-of-zigzag-arrays-ii/
 *
 * Approach: Matrix Exponentiation with Transition States
 * Model the problem as counting length-n sequences where elements alternate strictly up/down,
 * with values constrained to [l, r]. States encode the last value and direction (up/down),
 * building a 2m x 2m transition matrix where m = r - l + 1. Raise this matrix to the (n-1)th
 * power using fast matrix exponentiation to count valid zigzag sequences efficiently.
 *
 * Transition Matrix: size 2m x 2m where rows/cols [0..m-1] represent 'last value going down'
 * and [m..2m-1] represent 'last value going up'. Entry u[i][j+m]=1 if value j < i (can go up),
 * u[i+m][j]=1 if value j > i (can go down).
 *
 * Time Complexity: O(m^3 * log(n)) where m = r - l + 1, due to matrix multiplication of
 * (2m x 2m) matrices repeated log(n) times via binary exponentiation.
 * Space Complexity: O(m^2) for storing the transition and result matrices.
 *
 * Runtime: 556 ms | Memory: 51 MB
 */

class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size();
        int m = b[0].size();
        Matrix res(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix powMul(Matrix base, long long exp, Matrix res) {
        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        Matrix u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        Matrix dp(1, vector<long long>(size, 1));

        dp = powMul(std::move(u), n - 1, std::move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % MOD;
        }

        return ans;
    }
};
