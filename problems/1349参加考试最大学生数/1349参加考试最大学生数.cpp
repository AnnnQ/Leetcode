#include <iostream>
#include <vector>

using namespace std;

int maxStudents(vector<vector<char>> &seats) {
    if (seats.empty()) return 0;

    int m = seats.size(); int n = seats[0].size();
    vector<pair<int, int>> dirs1 = {{1, -1}, {1, 0}, {-1, 0}, {-1, -1}};
    vector<pair<int, int>> dirs2 = {{1, 1}, {-1, 1}};

    auto canSeat = [&](int x, int y) {
        if(seats[x][y]=='#') return false;
        for(auto& d: dirs1) {
            int nx = x + d.first; int ny = y + d.second;
            if(seats[nx][ny] == '.') {
                 
            }
        }
    }
}

int main()
{
    vector<vector<char>> seats = {

    };
    
    auto iMaxStudents = maxStudents(seats);
    cout << "Max Student In Text: " << iMaxStudents  << endl;

}