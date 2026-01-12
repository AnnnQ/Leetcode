#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int itotalwater = 0;
        int ifirst;
        for(int i = 0; i < height.size() - 1; i++)
        {
            if(height[i] > height[i + 1])
            {
                ifirst = i;
                int cur = ifirst + 1;
                int iend = ifirst + 1;
                bool bfound = false;
                for(cur; cur < height.size(); ++cur)
                {
                    if(height[cur] >= height[ifirst])
                    {
                        bfound = true;
                        iend = cur;
                        break;
                    }
                    else
                    {
                        if(height[cur] > height[iend])
                        {
                            iend = cur;
                        }
                    }
                }

                for(int j = ifirst + 1; j < iend; ++j)
                {
                    itotalwater += (min(height[ifirst], height[iend]) - height[j]);
                }

                i = iend - 1;
            }
        }
        return itotalwater;
    }
};

int main() 
{
    Solution sol;
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height1) << endl; // Output: 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << sol.trap(height2) << endl; // Output: 9

    return 0;
}