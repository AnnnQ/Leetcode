#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int calculateConstructionNum(int irow, int icol, vector<int> arr, int ilength, int imin) {
    int num = 0;
    
    for(int i = 0; i <= irow - ilength; i++) {
        for(int j = 0; j <= icol - ilength; j++) {
            int sum = 0;
            for(int k = 0; k < ilength; k++) {
                int f = 0;
                while(f < ilength) {
                    sum += arr[(i + k) * icol + j + f];
                    f++;
                }
            }   

            if(sum >= imin) {
                num++;
            }
        }
    }

    return num;
}

int main()
{
    int irow, icol, ilength, imin;
    cout << "输入内容";
    cin >> irow >> icol >> ilength >> imin;

    vector<int> arr(irow * icol);
    for(int i = 0; i < irow * icol; i++) {
        cin >> arr[i];
    }

    int result = calculateConstructionNum(irow, icol, arr, ilength, imin);
    cout << result << endl;

    system("pause"); // Pause to keep the terminal window open
    return 0;
}