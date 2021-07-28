class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum = 0;

       for (auto& e : nums)
       {
           sum += e;
       }

       int pre = 0;
       int cur = 0;

       for (int i = 0; i < nums.size(); i++)
       {
           cur += nums[i];

           if (pre == sum - cur)
           {
               return i;
           }
           pre = cur;
       }

       return -1;
    }
};