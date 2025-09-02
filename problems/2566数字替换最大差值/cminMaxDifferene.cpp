#include "common.h"

class Solution {
public:
    int cminMaxDifferene(int num) {
        string str_num = to_string(num);
        int min_num = num, max_num = num;
        for (char& c : str_num) {
            if (c == '9') continue; // Skip if the digit is 9
            char original = c;
            c = '9'; // Change to 9 for max
            max_num = max(max_num, stoi(str_num));
            c = '0'; // Change to 0 for min
            min_num = min(min_num, stoi(str_num));
            c = original; // Restore original digit
        }
    }
};