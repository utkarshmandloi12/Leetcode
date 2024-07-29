// Approch 1 - DP

// class Solution
// {
// public:
//     int numTeams(vector<int> &rating)
//     {
//         int n = rating.size(), c = 0;

//         for (int mid = 0; mid < n; mid++)
//         {
//             int l = 0, r = 0;

//             for (int i = mid - 1; i >= 0; i--)
//             {
//                 if (rating[i] < rating[mid])
//                     l++;
//             }
//             for (int j = mid + 1; j < n; j++)
//             {
//                 if (rating[mid] < rating[j])
//                     r++;
//             }

//             c += l * r;

//             l = mid - l;
//             r = n - mid - 1 - r;

//             c += l * r;
//         }

//         return c;
//     }
// };

// Approch 2 - brute force

class Solution
{
public:
    int numTeams(vector<int> &r)
    {
        int n = r.size(), c = 0;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (r[i] < r[j] && r[j] < r[k])
                        c++;
                    if (r[i] > r[j] && r[j] > r[k])
                        c++;
                }
            }
        }

        return c;
    }
};
