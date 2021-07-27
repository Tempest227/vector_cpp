class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {0};

        for (auto e : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                if ((e >> i) & 1 == 1)
                    cnt[i]++;
            }
        }

        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            cnt[i] %= 3;

            if (cnt[i] == 1)
            {
                ret += (cnt[i] << i);
            }
        }

        return ret;
    }
};