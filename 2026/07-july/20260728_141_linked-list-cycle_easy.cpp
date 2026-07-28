/*
 * Problem #141: Linked List Cycle (Easy)
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Approach: Floyd's Cycle Detection Algorithm (Tortoise and Hare)
 * Two pointers, slow and fast, traverse the list simultaneously where slow moves
 * one step at a time and fast moves two steps. If a cycle exists, fast will
 * eventually lap slow and they will meet at the same node. If no cycle exists,
 * fast will reach the end (null) and we return false.
 *
 * Time Complexity : O(n) - In the worst case (cycle present), fast pointer laps
 *                   slow within one full cycle traversal.
 * Space Complexity: O(1) - Only two pointers are used regardless of list size.
 *
 * Runtime : 3 ms
 * Memory  : 11.8 MB
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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
