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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head, *slow = head;
        int c = 0;

        while (fast && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == NULL || fast->next == NULL)
                return NULL;
            if (fast == slow)
                break;
        }

        while (head != fast) {
            head = head->next, fast = fast->next;
        }

        return head;
    }
};