class Solution{
public:
    int searchInsert(vector<int> &nums, int target){
        int s = 0, e = nums.size();
        int m;

        if (target > nums[e - 1])
            return e;
        while (s <= e){
            m = (s + e) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                s = ++m;
            else
                e = --m;
        }

        return s;
    }
};