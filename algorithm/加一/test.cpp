class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;
        int next = 0;
        
        while(end >= 0)
        {
            int t;
            if (end == digits.size() - 1)
                t = digits[end] + 1;
            else
                t = digits[end] + next;

            if (t > 9)
                next = 1;                
            else
                next = 0;

            digits[end] = t % 10;
            end--;
        }
        if (next)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};