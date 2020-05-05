#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N = 10000;
const int M = 26;
int cnt[M];

void solve() {
    int U;
    cin >> U;
    memset(cnt, 0, sizeof(cnt));
    set<char> occur;
    for (int i = 0; i < N; i++) {
        long long M;
        string R;
        cin >> M >> R;
        occur.insert(R.begin(), R.end());
        cnt[R[0] - 'A']++;
    }

    vector<char> vec;
    for (int i = 0; i < M; i++) {
        char ch = i + 'A';
        if (cnt[i] > 0) {
            vec.push_back(ch);
            occur.erase(ch);
        }
    }

    sort(vec.begin(), vec.end(), [](const char a, const char b)->bool {
        return cnt[a - 'A'] > cnt[b - 'A'];
    });
    
    string ans(vec.data(), vec.size());
    for (char ch: occur) {
        ans = ch + ans;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << Case++ << ": ";
        solve();
    }
    return 0;
}
