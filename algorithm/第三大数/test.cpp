class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int end = nums.size() - 1;
        int flag = 2;
        int max = nums[end];
        while(end > 0 && flag > 0)
        {
            end--;            
            int t = nums[end];

            if (t != max)
            {
                flag--;
                max = t;
            }
        }
        return flag == 0?max:nums[nums.size() - 1];
    }
};