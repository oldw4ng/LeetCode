/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (45.64%)
 * Likes:    1276
 * Dislikes: 112
 * Total Accepted:    337.6K
 * Total Submissions: 739.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next)
            return head;
        
        ListNode* res = new ListNode(1);
        res -> next = head;
        ListNode* p = head;
        ListNode* q = res;
        while (p && p -> next) {
            q -> next = p -> next;
            q = p -> next;
            p -> next = q -> next;
            q -> next = p;
            q = p;
            p = p -> next;
        }
        return res -> next;
    }
};

