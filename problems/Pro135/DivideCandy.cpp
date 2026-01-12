#include "common.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i = 0; i < ratings.size(); ++i) {
            if(i > 0 && ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int j = ratings.size() - 1; j >= 0; --j) {
            if(j < ratings.size() - 1 && ratings[j] > ratings[j + 1]) {
                candies[j] = max(candies[j], candies[j + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution sol;
    vector<int> ratings1 = {1, 0, 2};
    cout << sol.candy(ratings1) << endl; // Output: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << sol.candy(ratings2) << endl; // Output: 4

    return 0;
}