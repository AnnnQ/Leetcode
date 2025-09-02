#include "common.h"
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    int count = 0;
    int irow = 0, icol = 0;
    res.reserve(m * n);
    //res.push_back(mat[0][0]);
    //count++;
    while (irow < m || icol < n) {
        //奇数对角线从右上到左下，即行加一，列减一
        if (count % 2 == 1) 
        {
            if(irow < m && icol >= 0)
            {
                res.push_back(mat[irow][icol]);
                icol -= 1;
                irow += 1;
            }
            else if(icol < 0 && irow < m)
            {
                count++;
                //irow += 1;
                icol += 1;
            }
            else if(/*icol < 0 &&*/ irow >= m)
            {
                count++;
                icol += 2;
                irow -= 1;
            }
        }
        //偶数对角线从左下到右上，即列加一，行减一
        else if(count % 2 == 0)
        {
            if(icol < n && irow >= 0)
            {
                res.push_back(mat[irow][icol]);
                icol += 1;
                irow -= 1;
            }
            else if(irow < 0 && icol < n)
            {
                count++;
                irow += 1;
            }
            else if(/*irow < 0 &&*/ icol >= n)
            {
                count++;
                irow += 2;
                icol -= 1;
            }
            // else if(icol >= n)
            // {
            //     count++;
            //     irow += 1;
            //     icol -= 1;
            // }
            
        }

    }
    return res;
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = findDiagonalOrder(mat);
    for(auto a : res)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}