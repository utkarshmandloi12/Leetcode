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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head->next, *newhead = new ListNode(head->val);
        while (temp != NULL) {
            ListNode* new_node = new ListNode(temp->val);
            new_node->next = newhead;
            newhead = new_node;
            temp = temp->next;
        }
        return newhead;
    }
};