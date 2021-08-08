class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        int ans = INT_MIN;
        for (int i = 1; i < array.size(); i++)
        {
            if (dp[i - 1] < 0)
            {
                dp[i] = array[i];
            }
            else
            {
                dp[i] = dp[i - 1] + array[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};