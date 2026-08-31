/*
 * Problem 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 *
 * Approach:
 * The key insight is that the maximum distance between critical points is always determined by the span between the very first and the very last critical points found, while the minimum distance must exist between two adjacent critical points. Using a single-pass state-tracking traversal with a 3-pointer sliding window, we can identify local extrema by comparing each node to its immediate predecessor and successor. Rather than allocating an auxiliary list to store all critical indices, we optimize space by maintaining only three state variables: the index of the first critical point, the index of the most recently found critical point, and the current index. This allows us to greedily update the minimum adjacent distance and calculate the total maximum span in a single traversal, ensuring optimal memory efficiency.
 *
 * Time Complexity: O(N) — We perform a single linear traversal over the linked list of length N, where each step involves a constant number of comparisons to detect local extrema.
 * Space Complexity: O(1) — We track critical points using a constant number of integer variables, avoiding the O(N) space complexity of storing all critical indices in an auxiliary array.
 *
 * Runtime: 4 ms | Memory: 124.7 MB
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};

        // Initialize minimum distance to the maximum possible value
        int minDistance = INT_MAX;

        // Pointers to track the previous node, current node, and indices
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentIndex = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (currentNode->next != nullptr) {
            // Check if the current node is a local maxima or minima
            if ((currentNode->val < previousNode->val &&
                 currentNode->val < currentNode->next->val) ||
                (currentNode->val > previousNode->val &&
                 currentNode->val > currentNode->next->val)) {
                // If this is the first critical point found
                if (previousCriticalIndex == 0) {
                    previousCriticalIndex = currentIndex;
                    firstCriticalIndex = currentIndex;
                } else {
                    // Calculate the minimum distance between critical points
                    minDistance =
                        min(minDistance, currentIndex - previousCriticalIndex);
                    previousCriticalIndex = currentIndex;
                }
            }

            // Move to the next node and update indices
            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        // If at least two critical points were found
        if (minDistance != INT_MAX) {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }

        return result;
    }
};
