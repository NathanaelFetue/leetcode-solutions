/*
 * Problem #3518: Smallest Palindromic Rearrangement II (Hard)
 * URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
 *
 * Approach: Combinatorial ranking / lexicographic enumeration of unique palindrome permutations.
 * First, halve character counts to build the left half of the palindrome (handle odd-count middle char).
 * Then greedily pick each position of the left half by computing the count of unique permutations
 * of remaining characters using multinomial coefficients; decrement k accordingly until k=1.
 * The full palindrome is constructed as left + optional_mid_char + reverse(left).
 *
 * Time Complexity: O(n * 26^2) — for each of the n/2 positions we iterate over 26 characters
 * and compute a multinomial coefficient over up to 26 distinct counts.
 *
 * Space Complexity: O(n) — for storing the left half string and character count arrays.
 *
 * Runtime: 1467 ms | Memory: 17.2 MB
 */

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    unsigned long long c_n_k(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;
        unsigned long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }

    unsigned long long permutationsUniques(const std::vector<int>& counts) {
        unsigned long long res = 1;
        int total_restant = 0;
        for (int c : counts) total_restant += c;

        for (int c : counts) {
            if (c == 0) continue;
            res *= c_n_k(total_restant, c);
            total_restant -= c;
        }
        return res;
    }

    std::string smallestPalindrome(std::string s, int k) {
        int n = s.size();
        std::vector<int> counts(26, 0);
        for (char c : s) counts[c - 'a']++;

        int impairs = 0;
        std::string mid = "";
        int taille_left = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                impairs++;
                mid = std::string(1, 'a' + i);
            }
            counts[i] /= 2;
            taille_left += counts[i];
        }

        if (impairs > 1) return "";

        if (k > permutationsUniques(counts) || k <= 0) return "";

        std::string left = "";
        
        for (int p = 0; p < taille_left; ++p) {
            for (int i = 0; i < 26; ++i) {
                if (counts[i] == 0) continue;

                counts[i]--; 
                unsigned long long combinaisons_restantes = permutationsUniques(counts);

                if (k <= combinaisons_restantes) {
                    left += (char)('a' + i);
                    break;
                } 
                
                k -= combinaisons_restantes;
                counts[i]++;
            }
        }

        std::string right = left;
        std::reverse(right.begin(), right.end());
        return left + mid + right;
    }
};

