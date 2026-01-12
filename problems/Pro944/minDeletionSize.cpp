#include "common.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int icolnum = strs[0].size();
        int istringnum = strs.size();
        int iret = 0;
        for(int i = 0; i < icolnum; i++)
        {
            for(int j = 0; j < istringnum - 1; j++)
            {
                if(strs[j][i] > strs[j + 1][i])
                {
                    iret++;
                    break;
                }
            }
        }
        return iret;
    }
};

int main() {
    Solution sol;
    vector<string> strs1 = {"cba", "daf", "ghi"};
    cout << sol.minDeletionSize(strs1) << endl; // Output: 1

    vector<string> strs2 = {"a", "b"};
    cout << sol.minDeletionSize(strs2) << endl; // Output: 0

    vector<string> strs3 = {"zyx", "wvu", "tsr"};
    cout << sol.minDeletionSize(strs3) << endl; // Output: 3

    return 0;
}