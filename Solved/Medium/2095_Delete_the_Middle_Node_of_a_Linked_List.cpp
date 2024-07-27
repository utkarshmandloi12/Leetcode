class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast == slow)
            return NULL;

        fast = head;

        while (fast->next != slow) fast = fast->next;

        fast->next = slow->next;

        return head;
    }
};