class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
     
        int start = 0;
        int end = 1;

        while(end < nums.size())
        {
            if (nums[start] != nums[end])
            {
                start++;
                end++;
            }
            else
            {
                return true;
            }
            
        }

        return false;
    }
};