/*
 * Problem #83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Hash Set with Dummy Node
 * A dummy node is prepended to simplify edge cases, and a set tracks all visited
 * node values. Traversing with a 'curr' pointer, if the next node's value already
 * exists in the set it is skipped by rewiring pointers; otherwise it is recorded
 * and the pointer advances normally.
 *
 * Time Complexity : O(n) — each node is visited at most once.
 * Space Complexity: O(k) — where k is the number of unique values stored in the set;
 *                   in the worst case O(n) if all values are distinct.
 *
 * Runtime : 0 ms
 * Memory  : 16.9 MB
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
        set <int> s = {};
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
