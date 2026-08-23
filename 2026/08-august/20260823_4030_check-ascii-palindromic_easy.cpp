/*
 * Problem 4030: Check ASCII Palindromic
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-ascii-palindromic/
 *
 * Approach:
 * The key insight is to transform the character-level palindrome check into a bit-level representation check by converting each ASCII character into its 8-bit binary equivalent. By flattening the entire string into a contiguous sequence of bits, we can determine if the overall binary structure is symmetric. The algorithm utilizes the two-pointer collision technique to validate symmetry from both ends of the concatenated binary string toward the center, failing early on any mismatch. This ensures that we verify the binary representation of the ASCII values as a unified palindromic sequence.
 *
 * Time Complexity: O(N) — where N is the length of the input string, driven by the linear pass to convert each character to an 8-bit representation and a subsequent linear scan of the resulting string of length 8N.
 * Space Complexity: O(N) — due to the allocation of a temporary binary string of size 8 * N to store the concatenated bitwise representations of the input characters.
 *
 * Runtime: 0 ms | Memory: 9.2 MB
 */

class Solution {
public:
    bool isPalindromic(string s) {
        string bin = "";
        for(char c : s) bin += bitset<8>(c).to_string();
        int l=0, r=bin.size() -1;
        while(l < r){
            if(bin[l] != bin[r]) return false;
            r--; l++;
        }
        return true;
    }
};
