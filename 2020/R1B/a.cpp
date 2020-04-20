#include <iostream>
#include <cassert>
#include <string>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
const char cmd[] = "SNEW";

bool finish(int x, int y) {
    return x == 0 && y == 0;
}

bool check(int x, int y) {
    if (abs(x + y) % 2 == 1) return true;
    return false;
}

string solve() {
    int x, y;
    cin >> x >> y;
    if (!check(x, y)) return "IMPOSSIBLE";
    string ans;
    while (x != 0 || y != 0) {
        //cout << x << " " << y << endl;
        int index = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //cout << nx << " " << ny << endl;
            if (abs(nx) % 2 == 1 || abs(ny) % 2 == 1) continue;
            if (finish(nx, ny)) {
                index = i;
                break;
            }
            if (check(nx / 2, ny / 2)) {
                index = i;
            }
        }
        assert(index != -1);
        x += dx[index];
        y += dy[index];
        x /= 2, y /= 2;
        ans += cmd[index];
    }

    return ans;
}

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << Case++ << ": " << solve() << endl;
    }
    return 0;
}

