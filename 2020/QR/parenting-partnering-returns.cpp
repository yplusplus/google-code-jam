#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 30 * 60;
int cnt[N];
int assignment[N];

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > activity(n);
    memset(cnt, 0, sizeof(cnt));
    memset(assignment, 0, sizeof(assignment));
    for (int i = 0; i < n; i++) {
        cin >> activity[i].first.first >> activity[i].first.second;
        activity[i].second = i;
        cnt[activity[i].first.first]++;
        cnt[activity[i].first.second]--;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += cnt[i];
        if (sum >= 3) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    sort(activity.begin(), activity.end());
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (activity[i].first.first >= last) {
            last = activity[i].first.second;
            assignment[activity[i].second] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (assignment[i]) cout << "J";
        else cout << "C";
    }
    cout << endl;
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

