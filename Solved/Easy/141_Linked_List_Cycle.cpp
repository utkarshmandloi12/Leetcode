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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;

        for (int i = 0; head != NULL; i++) {
            if (head->val == 100001)
                return true;

            head->val = 100001;

            head = head->next;
        }

        return false;
    }
};