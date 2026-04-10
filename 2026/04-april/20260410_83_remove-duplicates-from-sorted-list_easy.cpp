/*
 * Problem #83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Hash Set Tracking
 * Traverse the linked list while maintaining a set of seen values.
 * If the current node's value already exists in the set, bypass it by
 * linking the previous node directly to the next node. Otherwise, add
 * the value to the set and advance both pointers.
 *
 * Time Complexity: O(n log n) - each node is visited once, and each
 * set insertion/lookup takes O(log n) due to the ordered set structure.
 *
 * Space Complexity: O(n) - the set stores at most n unique values
 * where n is the number of nodes in the list.
 *
 * Runtime: 3 ms | Memory: 16.9 MB
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
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            if (s.contains(curr->val)) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                s.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
