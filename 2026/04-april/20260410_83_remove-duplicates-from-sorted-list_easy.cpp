/*
 * Problem 83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Use a hash set to track seen values while traversing the linked list
 * with a dummy node. For each node, if its value already exists in the set,
 * skip it by relinking pointers; otherwise, record the value and advance.
 *
 * Time Complexity: O(n) — each node is visited exactly once during traversal.
 * Space Complexity: O(n) — the set stores at most n unique values from the list.
 *
 * Note: Since the list is sorted, an O(1) space approach comparing adjacent nodes
 * is also valid, but this solution uses a set for generality.
 *
 * Runtime: 0 ms
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
