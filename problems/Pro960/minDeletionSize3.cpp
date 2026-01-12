#include "common.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        vector<int> dp(strs[0].size(), 1);

        for(int i = 0; i < strs[0].size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                bool flag = true;
                for(int k = 0; k < strs.size(); k++)
                {
                    if(strs[k][i] < strs[k][j])
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }
        }

        return strs[0].size() - *max_element(dp.begin(), dp.end());

    }
};

int main() {
    Solution sol;
    vector<string> strs1 = {"babca","bbazb"};
    cout << sol.minDeletionSize(strs1) << endl; // Output: 1

    vector<string> strs2 = {"edcba"};
    cout << sol.minDeletionSize(strs2) << endl; // Output: 0

    vector<string> strs3 = {"ghi","def","abc"};
    cout << sol.minDeletionSize(strs3) << endl; // Output: 3

    return 0;
}