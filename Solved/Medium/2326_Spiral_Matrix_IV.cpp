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
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {

        vector<vector<int>> ans(m, vector<int>(n));

        int r = m, c = n, num = 1;
        int rc = 0, cc = 0, i = 0, rows = 0, cols = 0;

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (num <= n * m)
        {
            while (rc >= rows && rc < r && cc >= cols && cc < c)
            {
                if (head != NULL)
                    ans[rc][cc] = head->val, head = head->next;
                else
                    ans[rc][cc] = -1;
                rc += dir[i][0];
                cc += dir[i][1];
                num++;
            }
            rc -= dir[i][0], cc -= dir[i][1];
            if (i == 0)
                rows++;
            if (i == 1)
                c--;
            if (i == 2)
                r--;
            if (i == 3)
                cols++;

            i = (i + 1) % 4;
            rc += dir[i][0], cc += dir[i][1];
        }

        return ans;
    }
};