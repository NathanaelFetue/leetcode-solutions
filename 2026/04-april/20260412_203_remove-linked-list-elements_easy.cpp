/*
 * 203. Remove Linked List Elements - Easy
 * https://leetcode.com/problems/remove-linked-list-elements/
 *
 * Approach: Two-pointer traversal with a dummy head node.
 * A dummy node is prepended to handle edge cases where the head itself needs removal.
 * We maintain a 'prev' pointer and a 'tmp' traversal pointer; when tmp's value matches val,
 * we skip it by linking prev->next directly to tmp->next, otherwise advance prev forward.
 *
 * Time Complexity: O(n) - single pass through all n nodes in the linked list.
 * Space Complexity: O(1) - only a constant number of extra pointers are used (dummy, prev, tmp).
 *
 * Runtime: 0 ms
 * Memory: 20.1 MB
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* tmp  = head;
        while(tmp){
            if(tmp-> val == val) {
                prev -> next = tmp -> next;
            } else {
                prev = prev -> next;
            }
            tmp = tmp -> next;
        }
        return dummy -> next;;
    }
};
