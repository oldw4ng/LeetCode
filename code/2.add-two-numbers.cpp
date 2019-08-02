/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.50%)
 * Likes:    5610
 * Dislikes: 1445
 * Total Accepted:    953.6K
 * Total Submissions: 3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        int sum = l1 -> val + l2 -> val;
        int carry = sum / 10;
        result -> val = sum % 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
        while(l1 && l2) {
            result -> next = new ListNode(0);
            result = result -> next;
            sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            result -> val = sum % 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1) {
            result -> next = new ListNode(0);
            result = result -> next;
            sum = l1 -> val + carry;
            carry = sum / 10;
            result -> val = sum % 10;
            l1 = l1 -> next;
        }
        while (l2) {
            result -> next = new ListNode(0);
            result = result -> next;
            sum = l2 -> val + carry;
            carry = sum / 10;
            result -> val = sum % 10;
            l2 = l2 -> next;
        }
        if (carry) {
            result -> next = new ListNode(0);
            result = result -> next;
            sum = carry;
            carry = sum / 10;
            result -> val = sum % 10;
        }
        return head;
    }
};

