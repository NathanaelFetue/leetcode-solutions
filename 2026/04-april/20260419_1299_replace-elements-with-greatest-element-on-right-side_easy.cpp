/*
 * Problem #1299 - Replace Elements with Greatest Element on Right Side (Easy)
 * https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 *
 * Approach: Right-to-left single pass traversal.
 * We iterate from the last element to the first, maintaining a running maximum (maxE) of all elements seen so far to the right.
 * At each index, we replace the current element with maxE, then update maxE to be the maximum of itself and the original current value.
 * The last element is always replaced with -1 since there are no elements to its right.
 *
 * Time Complexity : O(n) - single pass through the array of size n.
 * Space Complexity : O(1) - in-place modification, only constant extra variables used.
 *
 * Runtime : 0 ms
 * Memory  : 72.6 MB
 */

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxE=-1 , n = arr.size();
        for(int i=n-1; i>=0; i--){
            int curr = arr[i] ;
            arr[i] = maxE;
            maxE = max(maxE , curr);
        }
        return arr;

    }
};
