/*
 * Problem #3606 - Coupon Code Validator (Easy)
 * URL: https://leetcode.com/problems/coupon-code-validator/
 *
 * Approach/Algorithm:
 * Iterate through all coupons and filter those that are active, have a non-empty
 * code containing only alphanumeric characters or underscores, and belong to a
 * valid business category stored in an unordered_set for O(1) lookup.
 * Valid coupons are collected as (code, businessLine) pairs, then sorted
 * primarily by businessLine and secondarily by code (both ascending).
 *
 * Time Complexity: O(n * L + n log n)
 *   - n = number of coupons, L = average code length for character validation
 *   - Sorting the valid pairs takes O(n log n)
 *
 * Space Complexity: O(n)
 *   - O(n) for storing valid coupon pairs and result vector
 *   - O(1) extra for the fixed-size category set (4 entries)
 *
 * Runtime : 4 ms
 * Memory  : 69.4 MB
 */

class Solution {
    unordered_set<string> categorySet = {"electronics","grocery","pharmacy","restaurant"};

    bool isValid(const string& code, const string& business) {
        if (code.empty()) return false;
        for (char c : code)
            if (!isalnum(c) && c != '_') return false;
        return categorySet.count(business) > 0;
    }

    vector<string> sortBySecondThenFirst(vector<pair<string,string>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        vector<string> result;
        for (auto& [s1, s2] : pairs)
            result.push_back(s1);
        return result;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> valid;
        for (int i = 0; i < code.size(); i++)
            if (isActive[i] && isValid(code[i], businessLine[i]))
                valid.push_back({code[i], businessLine[i]});
        return sortBySecondThenFirst(valid);
    }
};
