class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for (auto& e : nums)
        // {
        //     e *= e;
        // }
        // sort(nums.begin(), nums.end());

        vector<int> ret(nums.size(), 0);
        int i = 0;
        int j = nums.size() - 1;
        int k = ret.size() - 1;

        while(i <= j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                ret[k] = nums[j] * nums[j];
                j--;
                k--;
            }
            else
            {
                ret[k] = nums[i] * nums[i];
                i++;
                k--;
            }
        }

        return ret;
    }
};