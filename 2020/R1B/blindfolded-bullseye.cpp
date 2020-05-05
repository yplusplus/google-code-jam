#include <iostream>
#include <random>
#include <string>
#include <cassert>
using namespace std;

using Point = pair<long long, long long>;
using LL = long long;

const LL BOUND = 1000000000LL;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<LL> dis(-BOUND, BOUND);
LL A, B;

string test(LL x, LL y) {
    cout << x << " " << y << endl;
    cout.flush();
    string res;
    cin >> res;
    return res;
}

Point random_find() {
    LL x, y;
    do {
        x = dis(gen);
        y = dis(gen);
    } while (test(x, y) != "HIT");
    return {x, y};
}

LL get_x(const Point &p) {
    LL x1, x2;
    LL L = -BOUND, R = p.first;
    while (L <= R) {
        LL mid = (L + R) >> 1;
        if (test(mid, p.second) == "HIT") {
            x1 = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    L = p.first, R = BOUND;
    while (L <= R) {
        LL mid = (L + R) >> 1;
        if (test(mid, p.second) == "HIT") {
            x2 = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return (x2 + x1) / 2;
}

LL get_y(const Point &p) {
    LL y1, y2;
    LL L = -BOUND, R = p.second;
    while (L <= R) {
        LL mid = (L + R) >> 1;
        if (test(p.first, mid) == "HIT") {
            y1 = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    L = p.second, R = BOUND;
    while (L <= R) {
        LL mid = (L + R) >> 1;
        if (test(p.first, mid) == "HIT") {
            y2 = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return (y2 + y1) / 2;
}


void solve() {
    Point p = random_find();
    LL x0 = get_x(p);
    LL y0 = get_y(p);
    assert(test(x0, y0) == "CENTER");
}

int main() {
    int T;
    cin >> T >> A >> B;
    while (T--) {
        solve();
    }
    return 0;
}
