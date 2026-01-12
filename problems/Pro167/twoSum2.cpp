#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        for(int i = 0; i < numbers.size() - 1; i++)
        {
            if(numbers[i] + numbers[numbers.size() - 1] < target)
            {
                continue;
            }

            for(int j = i + 1; j < numbers.size(); j++)
            {
                if(numbers[i] + numbers[j] > target)
                {
                    break;
                }
                
                if(numbers[i] + numbers[j] == target)
                {
                    ret.push_back(i + 1);
                    ret.push_back(j + 1);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> numbers = {-10,-8,-2,1,2,5,6};
    int target = 0;
    vector<int> ret = sol.twoSum(numbers, target);
    for(int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}