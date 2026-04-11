/*
 * Problem #141: Linked List Cycle (Easy)
 * URL: https://leetcode.com/problems/linked-list-cycle/
 *
 * Approach: Hash Set Node Tracking
 * Traverse the linked list while storing each visited node pointer in an unordered_set.
 * At each step, check if the next node has already been seen; if so, a cycle exists.
 * If traversal reaches a null next pointer, no cycle is present.
 *
 * Time Complexity: O(n) - each node is visited at most once before a cycle is detected
 *                   or the end of the list is reached.
 * Space Complexity: O(n) - in the worst case, all n node pointers are stored in the set
 *                    before a cycle is detected or the list ends.
 *
 * Runtime: 11 ms
 * Memory: 14.6 MB
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* tmp = head;
        unordered_set <ListNode*> seen;
        seen.insert(tmp);
        while(tmp->next) {
            if(seen.count(tmp ->next)) return true;
            seen.insert(tmp);
            tmp = tmp-> next;
        }
        return false;
        
    }
    set<ListNode*> seen;
};
