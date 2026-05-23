/*
 * Problem #347: Top K Frequent Elements (Medium)
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Approach: Frequency Count + Sorting
 * First, build a frequency map using an unordered_map to count occurrences of each element.
 * Convert the map to a vector of pairs and sort it in descending order by frequency.
 * Finally, extract the first k elements from the sorted vector as the result.
 *
 * Time Complexity: O(n log n) - where n is the number of unique elements;
 * sorting the frequency vector dominates the overall complexity.
 *
 * Space Complexity: O(n) - for storing the frequency map and the vector of pairs,
 * where n is the number of unique elements in the input.
 *
 * Runtime: 0 ms
 * Memory: 18 MB
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;

        for(int i =0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> res;
        for(int i=0; i<k; i++) {
            res.push_back(vec[i].first);
        }

        return res;
    }
};

