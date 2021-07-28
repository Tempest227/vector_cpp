class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        //先添加空集
        result.push_back(vector<int>{});
        //遍历nums中的每个元素
        for (auto num : nums)
        {
            //将num添加到result的每个元素中，得到新的子集
            vector<vector<int>> temp;
            for (auto res : result)
            {
                vector<int> r(res);
                r.push_back(num);
                temp.push_back(r);
            }
            //将temp中的子集添加到result
            for (auto t : temp)
            {
                result.push_back(t);
            }
        }
        return result;
    }
};