/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.36%)
 * Likes:    2732
 * Dislikes: 175
 * Total Accepted:    425.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    struct cmp {
        bool operator()(const ListNode* p1, const ListNode* p2) {
            return p1 -> val > p2 -> val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> nodes;
        for (auto item : lists) {
            if (item) {
                nodes.push(item);
            }
        }
        if (!nodes.empty()) {
            root = nodes.top();
            nodes.pop();
            if (root -> next) {
                nodes.push(root -> next);
            }
        }
        ListNode *p = root;
        while (!nodes.empty()) {
            p -> next = nodes.top();
            nodes.pop();
            p = p -> next;
            if (p -> next) {
                nodes.push(p -> next);
            }
        }
        return root;
    }
};

