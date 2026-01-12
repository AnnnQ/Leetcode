#include "common.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
     {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int ileft, iright;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            ileft = i + 1;
            iright = nums.size() - 1;
            while(ileft < iright)
            {
                if(nums[ileft] + nums[iright] > -nums[i])
                {
                    int temp = nums[iright];
                    while(temp == nums[iright] && iright > ileft)
                        iright -= 1;
                }
                else if (nums[ileft] + nums[iright] < -nums[i])
                {
                    int temp = nums[ileft];
                    while(temp == nums[ileft] && iright > ileft)
                        ileft += 1;
                }
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[ileft]);
                    temp.push_back(nums[iright]);
                    ret.push_back(temp);
                    int itemp = nums[iright];
                    while(itemp == nums[iright] && iright > ileft)
                        iright -= 1;
                }
            }

        }
        return ret;
            
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}