/*
 * 725. Split Linked List in Parts
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/split-linked-list-in-parts/
 *
 * Approach:
 * First, count the total number of nodes in the linked list. Compute the base
 * part size as totalNodes / k and the number of parts that get an extra node
 * as totalNodes % k. Iterate k times, assigning each part its computed size,
 * severing the next pointer to split the list, and advancing to the next segment.
 *
 * Time Complexity: O(n) — single pass to count nodes, then one pass to split.
 * Space Complexity: O(k) — output vector of size k (excluding input list).
 *
 * Runtime: 0 ms
 * Memory: 13.7 MB
 */

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int nbNodes = 0;
        ListNode* tmp = head;
        while (tmp) { nbNodes++; tmp = tmp->next; }

        int base = nbNodes / k;
        int extra = nbNodes % k;

        vector<ListNode*> res;
        tmp = head;

        for (int i = 0; i < k; i++) {
            res.push_back(tmp);
            int partSize = base + (i < extra ? 1 : 0);
            for (int j = 0; j < partSize - 1; j++)
                tmp = tmp->next;
            if (tmp) {
                ListNode* next = tmp->next;
                tmp->next = nullptr;
                tmp = next;
            }
        }
        return res;
    }
};
