/*
 * Problem #83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Use a set to track all values seen so far while traversing the linked list
 * with a dummy head node. For each node, if its value already exists in the set,
 * skip it by relinking pointers; otherwise, record the value and advance the pointer.
 *
 * Time Complexity: O(n log n) - each of the n nodes is visited once, and set insertion
 * and lookup each take O(log n) time.
 *
 * Space Complexity: O(n) - the set stores at most n unique values from the list.
 *
 * Runtime: 1 ms
 * Memory: 16.9 MB
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
    ListNode* deleteDuplicates(ListNode* head) {
        set <double> s = {};
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while(curr -> next) {
            if (s.contains(curr->next -> val)) {
                curr -> next = curr -> next -> next ;
            } else {
                s.insert(curr ->next-> val);
                curr = curr -> next;
            }
        } 
        return dummy.next;
    }
};
