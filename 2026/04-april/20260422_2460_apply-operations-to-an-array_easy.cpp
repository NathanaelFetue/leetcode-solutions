/*
 * Problem #2460: Apply Operations to an Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/apply-operations-to-an-array/
 *
 * Approach/Algorithm:
 * First, iterate through the array and for each pair of adjacent equal elements,
 * double the left element and set the right element to zero. Then use a two-pointer
 * technique to shift all non-zero elements to the front, filling the remaining positions
 * with zeros to preserve array length.
 *
 * Time Complexity: O(n) - Two linear passes over the array of size n.
 * Space Complexity: O(1) - All operations are performed in-place with no extra space.
 *
 * Runtime: 0 ms
 * Memory: 13.1 MB
 */

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=1; i< nums.size(); i++) {
            if(nums[i] == nums[i-1]){
                nums[i-1] = 2*nums[i]; nums[i] =0;  
            }
        }
        int k =0;
        for(int i =0; i< nums.size(); i++){
            if(nums[i] != 0){
                nums[k++] = nums[i];
            }
        }
        for(int j =k; j<nums.size(); j++) nums[j] =0;
        return nums;
    }
};
