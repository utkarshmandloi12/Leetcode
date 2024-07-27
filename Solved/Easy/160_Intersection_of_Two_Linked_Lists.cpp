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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL)
            return headB;
        if (headB == NULL)
            return headA;

        ListNode *tempA = headA, *tempB = headB;
        int counta = 0, countb = 0;

        while (tempA != NULL || tempB != NULL) {
            if (tempA != NULL)
                counta++, tempA = tempA->next;
            if (tempB != NULL)
                countb++, tempB = tempB->next;
        }

        if (counta < countb) {
            for (int i = 0; i < countb - counta; i++) headB = headB->next;
        } else if (counta > countb) {
            for (int i = 0; i < counta - countb; i++) headA = headA->next;
        }

        while (headA != headB) {
            headA = headA->next, headB = headB->next;
        }

        return headA;
    }
};