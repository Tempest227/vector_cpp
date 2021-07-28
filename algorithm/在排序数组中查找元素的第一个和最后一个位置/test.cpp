class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return vector<int>{-1, -1};
        }

        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            if (nums[start] != target && nums[end] != target)
            {
                start++;
                end--;
            }
            else if (nums[start] == target && nums[end] != target)
            {
                end--;
            }
            else if (nums[start] != target && nums[end] == target)
            {
                start++;
            }
            else
            {
                return vector<int>{start, end};
            }
        }
        return vector<int>{-1, -1};
    }
};