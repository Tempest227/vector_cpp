class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            XOR ^= nums[i];
        }

        int div = 1;
        while((div & XOR) == 0)
            div <<= 1;

        int ret1 = 0;
        int ret2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & div)
            {
                ret1 ^= nums[i];
            }
            else
            {
                ret2 ^= nums[i];
            }
        }

        return vector<int>{ret1, ret2};
    }
};