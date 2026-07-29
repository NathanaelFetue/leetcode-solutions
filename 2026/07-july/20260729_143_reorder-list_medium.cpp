/*
 * Problem #143: Reorder List (Medium)
 * https://leetcode.com/problems/reorder-list/
 *
 * Approach: Recursive tail-to-head interleaving.
 * In each recursive call, the last node is found by traversing to the second-to-last node,
 * then detached and inserted immediately after the head, effectively interleaving the tail
 * with the front. Recursion then proceeds on the sublist starting at head->next->next.
 *
 * Time Complexity: O(n^2) - each recursive call traverses up to O(n) nodes to find the
 * tail, and there are O(n/2) recursive calls total.
 *
 * Space Complexity: O(n) - due to the recursive call stack depth of O(n/2).
 *
 * Runtime: 695 ms
 * Memory: 22.6 MB
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
    void reorderList(ListNode* head) {
        if(head== NULL || head-> next== NULL || head-> next -> next == NULL) return;
        ListNode* tmp = head;

        while(tmp->next->next != NULL){
            tmp=tmp->next;
        }
        tmp->next->next = head->next;
        head->next = tmp->next;
        tmp->next = NULL;
        return reorderList(head->next->next);
    }
};
