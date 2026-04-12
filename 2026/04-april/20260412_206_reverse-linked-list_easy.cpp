/*
 * Problem #206 - Reverse Linked List (Easy)
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * Approach: Iterative in-place pointer reversal.
 * We maintain three pointers: prev (initially null), tmp (current node), and next (lookahead).
 * At each step, we redirect tmp->next to prev, then advance all pointers forward until tmp is null.
 *
 * Time Complexity: O(n) - each node is visited exactly once.
 * Space Complexity: O(1) - only a constant number of pointers are used regardless of list size.
 *
 * Runtime : 0 ms
 * Memory  : 13.5 MB
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr , *next = head , *tmp = head;
        while(tmp) {
            next = tmp -> next;
            tmp -> next = prev;
            prev = tmp;
            tmp = next;

        }
        return prev;
    }
};
