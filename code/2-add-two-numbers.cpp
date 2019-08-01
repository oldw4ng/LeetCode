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