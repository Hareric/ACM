class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    void clearAround(vector<vector<bool>>& grid, int i, int j)
    // DFS
    {
        grid[i][j] = 0;
        if (i<grid.size()-1&&grid[i+1][j] == 1)
            clearAround(grid, i+1, j);
        if (j<grid[0].size()-1&&grid[i][j+1] == 1)
            clearAround(grid, i, j+1);
        if (j>0&&grid[i][j-1] == 1)
            clearAround(grid, i, j-1);
        if (i>0&&grid[i-1][j] == 1)
            clearAround(grid, i-1, j);
    }
    int numIslands(vector<vector<bool>>& grid) {
        int num = 0;  // the number of islands
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    num ++;
                    clearAround(grid, i, j);
                }
            }
        }
        return num;
    }
};