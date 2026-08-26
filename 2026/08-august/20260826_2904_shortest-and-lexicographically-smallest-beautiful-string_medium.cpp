/*
 * Problem 2904: Shortest and Lexicographically Smallest Beautiful String
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 *
 * Approach:
 * The key insight to finding the shortest beautiful string is that any optimal substring must begin and end with '1' to avoid unnecessary padding. By utilizing an anchored search technique, we iterate through the string and treat each '1' as a fixed starting point `l`. We then expand a right pointer `r` until we encompass exactly `k` ones, guaranteeing that `s[l...r]` is the shortest valid beautiful substring starting at `l`. We then compare this candidate to our globally tracked best solution, updating it if the candidate is shorter, or lexicographically smaller when lengths are equal.
 *
 * Time Complexity: O(N^2) — The outer loop scans the string of length N, and for each '1' encountered, the inner loop expands up to N times to locate the k-th '1'. Extracting and comparing candidate substrings takes O(N) time, making the total worst-case time complexity O(N^2) which runs extremely fast for N <= 100.
 * Space Complexity: O(N) — This space is used to store the optimal result string and the temporary candidate substring during the comparative checks.
 *
 * Runtime: 2 ms | Memory: 8.7 MB
 */

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n= s.size();

        for(int l=0; l<n; l++){
            if(s[l] != '1') continue;

            int ones = 0;
            for(int r=l ; r<n; r++){
                if(s[r] == '1') ones++;
                if(ones == k){
                    string candidate = s.substr(l, r-l+1);
                    if( res.empty() || candidate.size() < res.size() || candidate.size() == res.size() && candidate < res){
                        res = candidate;
                    }
                    break;
                }
                
            }
        }


        return res;
    }
};
