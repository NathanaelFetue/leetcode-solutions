/*
 * Problem #143: Reorder List (Medium)
 * https://leetcode.com/problems/reorder-list/
 *
 * Approach: Recursive tail-insertion reordering.
 * At each recursive step, find the last node in the remaining list, detach it,
 * and insert it immediately after the current head. Then recurse on the sublist
 * starting two nodes ahead, effectively interleaving front and back nodes.
 *
 * Time Complexity: O(n^2) - each recursive call traverses the remaining list
 * to find the last node, and there are n/2 such calls.
 *
 * Space Complexity: O(n) - recursive call stack depth is O(n/2) due to
 * the recursive calls on the shortened list.
 *
 * Runtime: 701 ms
 * Memory: 22.7 MB
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
