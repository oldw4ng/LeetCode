/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (31.65%)
 * Likes:    992
 * Dislikes: 74
 * Total Accepted:    163.9K
 * Total Submissions: 517.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(!head || !(head -> next) || !(head -> next -> next)) return;
        ListNode *slow = head,*fast = head;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* mid = slow;
        ListNode* p = mid, *q = mid -> next;
        while (q -> next ) {
            ListNode* t = q;
            q = q -> next;
            t -> next = p;
            p = t;
        }
        q -> next = p;
        mid -> next = nullptr;
        p = head;
        if (q == mid) {
            return;
        }
        while (q -> next != mid) {
            ListNode* t = p -> next;
            p -> next = q;
            p = t;
            t = q -> next;
            q -> next = p;
            q = t;
        }
        ListNode* t = p -> next;
        p -> next = q;
        p = t;
        t = q -> next;
        q -> next = p;
        q = t;
        
    }
};

