#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int inumscount = nums.size();
        if (inumscount <= 2) return inumscount;

        int istart(2), iend(2);
        int itotal(2);
        while(iend < inumscount)
        {
            if(nums[iend] != nums[istart - 2])
            {
                nums[istart] = nums[iend];
                istart++;
                itotal++;
            }
            iend++;
        }
        return itotal;
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {0,1,2,2,2,2,2,3,4,4,4};
    int newLength = sol.removeDuplicates(nums);
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}