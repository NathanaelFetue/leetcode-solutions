/*
 * Problem #876 - Middle of the Linked List (Easy)
 * LeetCode URL: https://leetcode.com/problems/middle-of-the-linked-list/
 *
 * Approach: Slow and Fast Pointer (Floyd's Tortoise and Hare)
 * A dummy node is prepended before head, and two pointers are used: slow starts at
 * the dummy node while fast starts at head. Fast moves two steps at a time while slow
 * moves one step. When fast reaches the end, slow points one node before the middle,
 * so slow->next gives the correct middle node (second middle for even-length lists).
 *
 * Time Complexity: O(n) - each node is visited at most once as fast traverses the list.
 * Space Complexity: O(1) - only a constant number of pointers are used (plus one dummy node).
 *
 * Runtime: 0 ms
 * Memory: 10 MB
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head , *fast = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        slow = dummy;
        while(fast && fast->next){
            slow = slow-> next ;
            fast = fast->next->next;;
        }
        return slow->next;
    }
};
