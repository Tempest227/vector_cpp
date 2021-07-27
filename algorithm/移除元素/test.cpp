    class Solution {
        public:
        int removeElement(vector<int>& nums, int val) {
            int start = 0;
            int end = 0;

            while(start < nums.size())
            {
                if (nums[start] != val)
                {
                    nums[end] = nums[start];
                    end++;
                    start++;
                }
                else
                {
                    start++;
                }
            }
            return end;
    }
};