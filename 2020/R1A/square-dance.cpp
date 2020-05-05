#include <iostream>
#include <vector>
using namespace std;

using LL = long long;
int n, m;

vector<vector<int> > s;
vector<vector<int> > up;
vector<vector<int> > down;
vector<vector<int> > lt;
vector<vector<int> > rt;

void init() {
    up.clear(); up.resize(n, vector<int>(m, -1));
    down.clear(); down.resize(n, vector<int>(m, -1));
    lt.clear(); lt.resize(n, vector<int>(m, -1));
    rt.clear(); rt.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            lt[i][j] = j - 1;
        }
        for (int j = 0; j < m - 1; j++) {
            rt[i][j] = j + 1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            up[i][j] = i - 1;
        }
        for (int i = 0; i < n - 1; i++) {
            down[i][j] = i + 1; 
        }
    }
}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool check_elimate(int x, int y) {
    LL sum = 0, cnt = 0;
    if (up[x][y] != -1) { cnt++; sum += s[up[x][y]][y]; }
    if (down[x][y] != -1) { cnt++; sum += s[down[x][y]][y]; }
    if (lt[x][y] != -1) { cnt++; sum += s[x][lt[x][y]]; }
    if (rt[x][y] != -1) { cnt++; sum += s[x][rt[x][y]]; }
    return cnt * s[x][y] < sum;
}

LL remove(int x, int y, vector<pair<int, int>> &candidates) {
    if (up[x][y] != -1) { down[up[x][y]][y] = down[x][y]; candidates.push_back({up[x][y], y}); }
    if (down[x][y] != -1) { up[down[x][y]][y] = up[x][y]; candidates.push_back({down[x][y], y}); }
    if (lt[x][y] != -1) { rt[x][lt[x][y]] = rt[x][y]; candidates.push_back({x, lt[x][y]}); }
    if (rt[x][y] != -1) { lt[x][rt[x][y]] = lt[x][y]; candidates.push_back({x, rt[x][y]}); }
    return s[x][y];
}

LL solve() {
    cin >> n >> m;
    init();
    s.resize(n);
    for (int i = 0; i < n; i++) {
        s[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    LL sum = 0;
    vector<pair<int, int>> elimate;
    vector<vector<bool>> visit(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += s[i][j];
            if (check_elimate(i, j)) {
                visit[i][j] = true;
                //cout << i << " " << j << endl;
                elimate.push_back({i, j});
            }
        }
    }
    LL ans = sum;
    while (!elimate.empty()) {
        vector<pair<int, int> > candidates;
        for (auto p: elimate) {
            sum -= remove(p.first, p.second, candidates);
        }
        ans += sum;
        
        elimate.clear();
        for (auto p: candidates) {
            int x = p.first, y = p.second;
            if (visit[x][y]) continue;
            if (check_elimate(x, y)) {
                visit[x][y] = true;
                //cout << p.first << " " << p.second << endl;
                elimate.push_back(p);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << Case++ << ": " << solve() << endl;
    }
    return 0;
}
