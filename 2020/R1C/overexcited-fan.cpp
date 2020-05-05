#include <iostream>
#include <string>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int char2dir(char ch) {
    switch (ch) {
        case 'N': return 1;
        case 'S': return 0;
        case 'W': return 2;
        case 'E': return 3;
    }
    return -1;
}

void solve() {
    int x, y;
    string tour;
    cin >> x >> y >> tour;
    pair<int, int> peppurr(x, y);
    if (peppurr == pair<int, int>{0, 0}) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < tour.size(); i++) {
        int dir = char2dir(tour[i]);
        peppurr.first += dx[dir];
        peppurr.second += dy[dir];
        if (abs(peppurr.first) + abs(peppurr.second) <= i + 1) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << Case++ << ": ";
        solve();
    }

    return 0;
}
