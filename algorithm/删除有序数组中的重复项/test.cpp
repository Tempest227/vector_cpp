class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return NULL;
        }
        
        int start = 0;
        int end = 1;

        while(end < nums.size())
        {
            if (nums[end] != nums[start])
            {
                start++;
                nums[start] = nums[end];
            }
            end++;
        }

        return start + 1;
    }
};