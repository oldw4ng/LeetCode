/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.19%)
 * Likes:    2454
 * Dislikes: 349
 * Total Accepted:    636.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l1 && l2) {
            if (l1 -> val < l2 -> val) {
                p -> next = l1;
                l1 = l1 -> next;
            } else {
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }
        if (l1)
            p -> next = l1;
        if (l2)
            p -> next = l2;
        return head -> next;
    }
};

