/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (64.22%)
 * Likes:    5730
 * Dislikes: 109
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        auto p = head;
        while (p -> next)
            p = p -> next;
        reverse(head);
        head -> next = nullptr;
        return p;
    }

    ListNode* reverse(ListNode* head) {
        if (!(head -> next)) {

            return head;
        }
        reverse(head -> next) -> next = head;
        return head;
    }
};
// @lc code=end

