#include "common.h"

class Solution {
public:

    vector<vector<int>> idirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    vector<vector<int>> res;
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int imax = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int idir = 0; idir < 4; idir++)
                    {
                        res.clear();
                        vector<int> vnext = {i, j};
                        res.push_back(vnext);
                        int ilen = 1;
                        if(i + idirs[idir][0] < 0 || i + idirs[idir][0] >= m || 
                            j + idirs[idir][1] < 0 || j + idirs[idir][1] >= n )
                            continue;
                        else if(grid[i + idirs[idir][0]][j + idirs[idir][1]] != 2)
                            continue;
                        else
                        {
                            vector<int> vnext1 = {i + idirs[idir][0], j + idirs[idir][1]};
                            res.push_back(vnext1);
                            ilen += theLongestNum(i + idirs[idir][0], j + idirs[idir][1], idir, true, grid) + 1;
                            imax = max(imax, ilen);
                        }       
                    }
                }
            }
        }

        if(imax == 0)
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 1)
                    return 1;
                }
            }
        }

        return imax;
    }
    
    int theLongestNum(int x, int y, int idir, bool bcanturn, vector<vector<int>>& grid)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        int nextx = x + idirs[idir][0];
        int nexty = y + idirs[idir][1];

        //下一步超出范围，则进行转向处理
        if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n )
            //|| grid[nextx][nexty] ==  1 || (grid[nextx][nexty] == 2 && grid[x][y] != 0) || 
            //(grid[nextx][nexty] == 0 && grid[x][y] != 2))
        {
            if(bcanturn)
            {
                idir = (idir + 1) % 4;
                // nextx = x + idirs[idir][0];
                // nexty = y + idirs[idir][1];
                // bcanturn = false;
                return theLongestNum(x, y, idir, false, grid);
            }
            else
            {
                return 0;
            }
        }

        if(grid[nextx][nexty] ==  1 || (grid[nextx][nexty] == 2 && grid[x][y] == 2) || (grid[nextx][nexty] == 0 && grid[x][y] != 2))
        {
            if(bcanturn)
                        {
                idir = (idir + 1) % 4;
                // nextx = x + idirs[idir][0];
                // nexty = y + idirs[idir][1];
                // bcanturn = false;
                return theLongestNum(x, y, idir, false, grid);
            }
            else
            {
                return 0;
            }
        }
        
        if(bcanturn)
        {
            int len1 = theLongestNum(nextx, nexty, idir, true, grid) + 1;
            int nextx2 = x + idirs[(idir + 1) % 4][0];
            int nexty2 = y + idirs[(idir + 1) % 4][1];

            if(nextx2 < 0 || nextx2 >= m || nextx2 < 0 || nextx2 >= n
                || grid[nextx2][nexty2] ==  1 || (grid[nextx2][nexty2] == 2 && grid[x][y] == 2) 
                || (grid[nextx2][nexty2] == 0 && grid[x][y] != 2))
                return len1;
            
            int len2 = theLongestNum(nextx2, nexty2, (idir + 1) % 4, false, grid) + 1;
            if(len1 >= len2)
            {
                vector<int> vnext = {nextx, nexty};
                res.push_back(vnext);
            }
            else
            {
                vector<int> vnext = {nextx2, nexty2};
                res.push_back(vnext);
            }
            return max(len1, len2);
        }
        else
        {
            vector<int> vnext = {nextx, nexty};
            res.push_back(vnext);
            return theLongestNum(nextx, nexty, idir, false, grid) + 1;
        }
            

        // //如果在范围内，开始处理数值是否按规律排列
        // if(grid[nextx][nexty] ==  1 || (grid[nextx][nexty] == 2 && grid[x][y] != 0) || 
        //     (grid[nextx][nexty] == 0 && grid[x][y] != 2))
        // {
        //     if(bcanturn)
        //     {
        //         idir = (idir + 1) % 4;
        //         // nextx = x + idirs[idir][0];
        //         // nexty = y + idirs[idir][1];
        //         // bcanturn = false;
        //         return theLongestNum(x, y, idir, false, grid) + 1;
        //     }
        //     else
        //     {
        //         return 0;
        //     }
        // }


    }
};

int main() {

    system("chcp 65001");

    Solution solution;
    
    // // 测试用例1: 基本情况
    // vector<vector<int>> grid1 = {
    //     {1,1,1},
    //     {1,1,1},
    //     {1,1,1}
    // };
    // cout << "测试用例1 结果: " << solution.lenOfVDiagonal(grid1) << endl;

        // 测试用例1: 基本情况
    //vector<vector<int>> grid1 = {
    //    {0}
    //};
    //cout << "测试用例1 结果: " << solution.lenOfVDiagonal(grid1) << endl;
    
    // 测试用例2: 包含0和2的情况
    vector<vector<int>> grid2 = {
        {0,2,0,2,0,2},
        {0,2,2,2,0,1},
        {0,2,0,0,0,2},
        {0,1,0,0,2,2},
        {0,2,0,2,2,1}
    };
    cout << "测试用例2 结果: " << solution.lenOfVDiagonal(grid2) << endl;
    
    // // 测试用例3: 更复杂的情况
    // vector<vector<int>> grid3 = {
    //     {1,2,0,1},
    //     {2,1,2,0},
    //     {0,2,1,2},
    //     {1,0,2,1}
    // };
    // cout << "测试用例3 结果: " << solution.lenOfVDiagonal(grid3) << endl;

    system("pause");
    return 0;
}