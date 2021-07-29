class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo)
    {
        if (memo[row][col] != 0)
            return memo[row][col];

        memo[row][col]++;
        for (auto dir : dirs)
        {
            int newRow = row + dir[0], newCol = col + dir[1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col])
                memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
        }
        return memo[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                ans = max(ans, dfs(matrix, i, j, memo));

        return ans;
    }
};