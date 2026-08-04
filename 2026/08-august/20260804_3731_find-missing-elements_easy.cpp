/*
 * Problem #3731 - Find Missing Elements
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-missing-elements/
 *
 * Approach/Algorithm:
 * First, find the minimum and maximum values in the array to define the range of interest.
 * Sort the array, then iterate over every integer in the range (minE, maxE) exclusive,
 * using binary search to check whether each candidate value exists in the sorted array.
 * Any value not found is appended to the result as a missing element.
 *
 * Time Complexity: O(n log n) — dominated by sorting the array and performing binary
 * search (O(log n)) for each of the O(n) values in the range.
 *
 * Space Complexity: O(n) — the result vector stores at most O(n) missing elements;
 * sorting is done in-place.
 *
 * Runtime: 0 ms | Memory: 32.4 MB
 */

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        int minE = *min_element(nums.begin() , nums.end()) , maxE = *max_element(nums.begin(),nums.end());
        sort(nums.begin() , nums.end());

        for(int i=0; i< (maxE - minE); i++){
            if( (i != 0) &&  (i != (maxE - minE))){
                bool found = binary_search(nums.begin(), nums.end(), minE+i);
                if(!found) res.push_back(minE+i);
            }
        }
        return res;
    }
};
