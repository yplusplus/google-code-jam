#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

using LL = long long;

const int N = 10000 + 100;
LL A[N], D;
int n;

LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

struct Fraction {
    Fraction() : x(0), y(1) {}
    Fraction(LL _x, LL _y) : x(_x), y(_y) {
        reduce();
    }
    void reduce() {
        LL d = gcd(x, y);
        x /= d;
        y /= d;
    }

    bool operator<(const Fraction &o) const {
        return x * o.y < y * o.x;
    }

    LL x, y;
};

Fraction get_limit(const vector<Fraction> &vec) {
    int L = 0, R = (int)vec.size() - 1;
    Fraction limit;
    while (L <= R) {
        int mid = (L + R) >> 1;
        const auto &f = vec[mid];
        LL cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += A[i] * f.y / f.x;
        }
        if (cnt >= D) {
            limit = f;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return limit;
}

LL calc(const vector<LL> &vec) {
    LL d = 0;
    LL res = 0;
    for (LL v: vec) {
        //cout << v << endl;
        if (D - d >= v) {
            res += v - 1;
            d += v;
        } else {
            res += D - d;
            d = D;
        }
        if (d >= D) break;
    }

    return D - d + res;
}

LL solve() {
    cin >> n >> D;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);

    map<Fraction, vector<LL> > cnt;
    vector<Fraction> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= D; j++) {
            Fraction f(A[i], j);
            vec.emplace_back(f);
            cnt[f].push_back(j);
        }
    }

    sort(vec.begin(), vec.end());
    Fraction limit = get_limit(vec);

    LL ans = D - 1;
    auto limit_it = cnt.upper_bound(limit);
    for (auto it = cnt.begin(); it != limit_it; it++) {
        //cout << "##" << endl;
        //cout << it->first.x << " " << it->first.y << endl;
        LL res = calc(it->second);
        if (res < ans) ans = res;
        //cout << res << endl;
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
