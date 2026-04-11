/*
 * Problem #141 - Linked List Cycle (Easy)
 * LeetCode URL: https://leetcode.com/problems/linked-list-cycle/
 *
 * Approach: Hash Set Node Tracking
 * Traverse the linked list and store each visited node's pointer in an unordered_set.
 * At each step, check if the next node already exists in the set; if so, a cycle is detected.
 * If traversal reaches a null next pointer, no cycle exists and we return false.
 *
 * Time Complexity: O(n) - Each node is visited at most once before a cycle is detected or
 * the end of the list is reached, where n is the number of nodes.
 *
 * Space Complexity: O(n) - The unordered_set stores up to n node pointers in the worst case
 * when no cycle exists.
 *
 * Runtime: 15 ms | Memory: 14.6 MB
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
