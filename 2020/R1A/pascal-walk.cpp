#include <iostream>
using namespace std;

const int K = 40;

void walk(int row, int dir, int limit) {
    int st = 1, ed = row + 1;
    if (dir == -1) st = row, ed = 0;
    int cnt = 0;
    for (int i = st; i != ed && cnt < limit; i += dir) {
        cout << row << " " << i << endl;
        cnt++;
    }
}

void solve() {
    long long n;
    cin >> n;
    if (n <= K) {
        for (int i = 1; i <= n; i++) {
            cout << i << " " << 1 << endl;
        }
        return;
    }

    n -= K;
    int cnt = 0;
    int dir = 1;
    for (int i = 1; i < 100; i++) {
        if (i <= 30 && (n >> (i - 1)) & 1) {
            walk(i, dir, i);
            dir *= -1;
        } else if (cnt < K) {
            walk(i, dir, 1);
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << Case++ << ": " << endl;
        solve();
    }

    return 0;
}
