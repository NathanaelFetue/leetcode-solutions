/*
 * Problem 1299: Replace Elements with Greatest Element on Right Side
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 *
 * Approach: Brute Force - For each element at index i, scan all elements to the right
 * to find the maximum value using a nested loop, tracking the index of the maximum.
 * Replace the current element with that maximum, and set the last element to -1.
 *
 * Time Complexity: O(n^2) - For each of the n elements, we scan up to n elements
 * to the right to find the maximum, resulting in quadratic time.
 *
 * Space Complexity: O(1) - The replacement is done in-place on the input array
 * with only a constant number of auxiliary variables used.
 *
 * Runtime: 2578 ms
 * Memory: 72.9 MB
 */

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int id =0 , n = arr.size();
        for(int i=0; i<n-1; i++){
            id = i+1;
            for(int j =id; j<n ; j++){
                if(arr[j] > arr[id]) id =j;
            }
            arr[i] = arr[id];
        }
        arr[n-1] = -1;
        return arr;

    }
};
