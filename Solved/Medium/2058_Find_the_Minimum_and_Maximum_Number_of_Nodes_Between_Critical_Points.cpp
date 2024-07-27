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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a(2, INT_MAX);
        int cmn = 0, cmx = 0, cc = 0;

        ListNode* temp = head->next;

        while (temp->next != nullptr) {
            if ((head->val > temp->val && temp->next->val > temp->val) ||
                (head->val < temp->val && temp->next->val < temp->val)) {
                if (cc) {
                    a[0] = min(a[0], cmn);
                    a[1] = cmx;
                }
                cc++;
                cmn = 0;
            }
            if (cc != 0) {
                cmx++;
                cmn++;
            }

            head = temp;
            temp = temp->next;
        }

        if (cc < 2)
            a[0] = a[1] = -1;

        return a;
    }
};