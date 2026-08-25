/*
 * Problem 3718: Smallest Missing Multiple of K
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/smallest-missing-multiple-of-k/
 *
 * Approach:
 * The key insight is to simplify the search for the smallest missing multiple of k by mapping each valid element in the array to its corresponding integer quotient coefficient, m = nums[i]/k. This solution utilizes a direct-address table to record which coefficients are present in the input array. By iterating through the array, we can mark visited quotients and subsequently scan the tracker starting from index 1 to find the first unmarked multiple. This direct tracking technique avoids the overhead of sorting or set hashing, yielding highly optimal performance.
 *
 * Time Complexity: O(N) — One linear scan of the input array to populate the quotient tracker, followed by a constant-bound scan of the tracker array.
 * Space Complexity: O(1) — A fixed-size auxiliary array of size 101 is used to track coefficient presence, resulting in constant space.
 *
 * Runtime: 0 ms | Memory: 24.5 MB
 */

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int res = k;
        vector<int> fact(101 , 1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%k == 0) {
                fact[(nums[i]/k)] = 0;
            }
        }
        int i=1;
        while(i < fact.size()){
            if(fact[i] ==1) break;
            i++;
        }
        return res*i;
    }
};
