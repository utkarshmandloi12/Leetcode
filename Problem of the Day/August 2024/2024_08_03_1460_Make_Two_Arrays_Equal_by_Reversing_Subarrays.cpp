
// class Solution // mininum time complexity
// {
// public:
//     bool canBeEqual(vector<int> &target, vector<int> &arr)
//     {
//         vector<int> mp(1000, 0);
//         for (int i = 0; i < arr.size(); i++)
//         {
//             mp[arr[i] - 1]++;
//             mp[target[i] - 1]--;
//         }
//         for (auto i : mp)
//         {
//             if (i != 0)
//                 return false;
//         }

//         return true;
//     }
// };

// class Solution
// {
// public:
//     bool canBeEqual(vector<int> &target, vector<int> &arr)
//     {
//         unordered_map<int, int> mp;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             mp[arr[i]]++;
//             mp[target[i]]--;
//         }
//         for (auto i : mp)
//         {
//             if (i.second != 0)
//                 return false;
//         }

//         return true;
//     }
// };

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return target == arr;
    }
};