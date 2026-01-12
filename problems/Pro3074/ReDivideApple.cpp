#include "common.h"

class Solution {
public:

    std::mt19937 rng{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};

    int partition(vector<int>& a, int l, int r) {
        std::uniform_int_distribution<int> dist(0, r - l);
        int pivot = a[l + dist(this->rng)];
        int i = l - 1, j = r + 1;
        while (true) {
            do { ++i; } while (a[i] > pivot);
            do { --j; } while (a[j] < pivot);
            if (i >= j) return j;
            swap(a[i], a[j]);
        }
    }

    void quicksort(vector<int>& a, int l, int r) {
        if (l >= r) return;
        int p = partition(a, l, r);
        quicksort(a, l, p);
        quicksort(a, p + 1, r);
    }

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int itotlalapple(0);
        for(int i = 0; i < apple.size(); i++)
        {
            itotlalapple += apple[i];
        }

        quicksort(capacity, 0, capacity.size() - 1);

        int iusedcapacity(0);
        int iboxes(0);
        for(int i = 0; i < capacity.size(); i++)
        {
            iusedcapacity += capacity[i];
            iboxes++;

            if(iusedcapacity >= itotlalapple)
            {
                break;
            }
        }

        return iboxes;

    }
};

int main() {
    Solution sol;
    vector<int> apple1 = {1,3,2};
    vector<int> capacity1 = {4,3,1,5,2};
    cout << sol.minimumBoxes(apple1, capacity1) << endl; // Expected output: 3

    vector<int> apple2 = {5, 5, 5};
    vector<int> capacity2 = {2,4,2,7};
    cout << sol.minimumBoxes(apple2, capacity2) << endl; // Expected output: 5

    return 0;
}