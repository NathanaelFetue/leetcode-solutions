/*
 * Problem #24 - Swap Nodes in Pairs
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Approach: Recursive pair swapping on a singly-linked list.
 * For each call, the first node (tmp) and second node (curr) are identified and swapped
 * by rewiring their next pointers, then the function recurses on the remaining list.
 * The new head of each pair (curr) is returned after linking it to the recursively swapped tail.
 *
 * Time Complexity : O(n) - each node is visited exactly once across all recursive calls.
 * Space Complexity: O(n) - implicit call stack depth is n/2 recursive frames, proportional to n.
 *
 * Runtime : 0 ms
 * Memory  : 11.1 MB
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *tmp = head, *curr;
        curr = tmp-> next;
        if(curr == nullptr) return tmp;
        tmp -> next = curr -> next;
        curr -> next = tmp;
        tmp -> next =  swapPairs(tmp -> next);
        return curr;
    }
};
