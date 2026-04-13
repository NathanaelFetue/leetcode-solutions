/*
 * Problem: Convert Binary Number in a Linked List to Integer
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 *
 * Approach: String construction with base-2 conversion.
 * Traverse the linked list from head to tail, appending each node's binary digit
 * to a string, then use stoi with base 2 to convert the binary string to a decimal integer.
 *
 * Time Complexity: O(n) - single pass through the linked list of n nodes.
 * Space Complexity: O(n) - string of length n is built to store binary digits.
 *
 * Runtime: 0 ms
 * Memory: 11.5 MB
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
    int getDecimalValue(ListNode* head) {
        ListNode *tmp = head;
        string s= "";
        while (tmp){
            s+= to_string(tmp -> val);
            tmp = tmp -> next;           
        }
        return (stoi(s, nullptr , 2));
    }
};
