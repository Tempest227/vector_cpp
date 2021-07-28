class Solution {
public:
    int compress(vector<char>& chars) {
        int reader = 0;
        int writer = 0;
        int start = 0;

        while(reader < chars.size())
        {
            //连续读到最后一个字符或当前字符!=下一个字符，开始写
            if (reader == chars.size() - 1 || chars[reader] != chars[reader + 1])
            {
                chars[writer++] = chars[start];
                //判断是否需要压缩
                if (reader > start)
                {
                    int cnt = reader - start + 1;
                    string cntStr = to_string(cnt);
                    for (char ch : cntStr)
                    {
                        chars[writer++] = ch;
                    }   
                }
                //写完，更新读起点
                start = reader + 1;
            }
            
            reader++;
        }
        return writer;
    }
};