/*
 * Problem 2948: Make Lexicographically Smallest Array by Swapping Elements
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
 *
 * Approach:
 * The key insight is that the swap operation is transitive: if we can swap element A with B, and B with C, we can rearrange {A, B, C} into any order at their original indices. By sorting a copy of the array, we can partition the elements into connected components (groups) where adjacent sorted elements have an absolute difference of at most 'limit'. Since elements within each component can be freely permuted, we can achieve the lexicographically smallest configuration by placing the sorted elements of each group back into their original relative positions. We map each number to its designated group ID and use queues (FIFO) to distribute the smallest available elements from each group back into the original array indices sequentially.
 *
 * Time Complexity: O(N log N) — dominated by sorting the array copy to find connected components, while the subsequent grouping and reconstruction steps take O(N) linear time.
 * Space Complexity: O(N) — required to store the sorted copy of the array, the element-to-group map, and the queue lists representing each group.
 *
 * Runtime: 347 ms | Memory: 234.4 MB
 */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if (groupToList.find(currGroup) == groupToList.end()) {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};
