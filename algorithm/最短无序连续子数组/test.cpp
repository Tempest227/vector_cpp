class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        vector<int> newNums(nums);

        sort(newNums.begin(), newNums.end());
        while(start < end)
        {
            if (nums[start] == newNums[start])
            {
                start++;
            }
            else if (nums[end] == newNums[end])
            {
                end--;
            }
            else
            {
                return end - start + 1;
            }
        }

        return 0;
    }
};