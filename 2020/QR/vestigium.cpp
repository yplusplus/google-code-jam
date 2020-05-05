#include <iostream>
#include <set>
using namespace std;

const int N = 100 + 10;
int a[N][N];
int n;

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i][i];
        }
        int row = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j < n; j++) {
                s.insert(a[i][j]);
            }
            if (s.size() != n) row++;
        }
        int col = 0;
        for (int j = 0; j < n; j++) {
            set<int> s;
            for (int i = 0; i < n; i++) {
                s.insert(a[i][j]);
            }
            if (s.size() != n) col++;
        }
        cout << "Case #" << Case++ << ": " << ans << " " << row << " " << col << endl;
    }
    return 0;
}
