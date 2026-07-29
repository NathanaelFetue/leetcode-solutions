/*
 * Problem #3518 - Smallest Palindromic Rearrangement II (Hard)
 * URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
 *
 * Approach: Combinatorial ranking / k-th permutation selection.
 * The left half of the palindrome is built character by character using a greedy strategy:
 * for each position, we try the smallest available character, count the number of unique
 * permutations of the remaining characters via multinomial coefficients C(n,k), and either
 * place that character (if k falls within its subtree) or subtract its count and move to the
 * next candidate. The right half is simply the reverse of the left half.
 *
 * Time Complexity: O(n * 26^2) where n is the length of the left half (~s.size()/2).
 * For each of the n positions we iterate over 26 letters and recompute permutationsUniques
 * (itself O(26)) giving O(n * 26 * 26).
 *
 * Space Complexity: O(n) for storing the left half string and the counts array of size 26.
 *
 * Runtime: 1470 ms | Memory: 17.1 MB
 */

#include <string>
#include <vector>
#include <algorithm>

// I've also done this , but TLE and naive non generalistic 
// approach to count factorielle instead C(n,k)
/*
class Solution {
public:
    unsigned long long factorielleRecursive(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorielleRecursive(n - 1);
    }
    
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        string left = s.substr(0, n/2) , rigth;
        if (k > factorielleRecursive(left.size())) return "";
        sort(left.begin() , left.end());
        vector <string> vec;
        string mid = (n%2 == 0) ? "": string(1, s[n/2]);

        do{
            rigth = left;
            reverse(rigth.begin() , rigth.end());
            vec.push_back(left+mid+rigth);

        } while ( next_permutation(left.begin() , left.end()) );

        if(k - 1 >= vec.size() || k <= 0){
            return "";
        }else  return vec[k-1];
    }
};
*/

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

