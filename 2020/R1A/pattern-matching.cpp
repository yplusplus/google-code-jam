#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int N = 100 + 10;
string pattern[N];
int n;

bool start_with(const string &s, const string &t) {
    if (t.length() > s.length()) return false;
    if (t.empty()) return true;
    return s.find(t) == 0;
}

bool end_with(const string &s, const string &t) {
    if (t.length() > s.length()) return false;
    if (t.empty()) return true;
    size_t pos = s.rfind(t);
    return pos == s.length() - t.length();
}

bool cmp(const string &a, const string &b) {
    return a.length() > b.length();
}

string solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pattern[i];
    string ans;
    vector<string> prefix, suffix;
    for (int i = 0; i < n; i++) {
        string pn = pattern[i];
        size_t lpos = pn.find('*');
        if (lpos > 0) prefix.push_back(pn.substr(0, lpos));
        size_t rpos = pn.rfind('*');
        if (rpos < pn.length()) suffix.push_back(pn.substr(rpos + 1));
        for (int j = lpos + 1; j < rpos; j++) {
            if (pn[j] != '*') ans += pn[j];
        }
    }

    sort(prefix.begin(), prefix.end(), cmp);
    for (int i = 1; i < prefix.size(); i++) {
        //cout << prefix[0] << " " << prefix[i] << endl;
        if (!start_with(prefix[0], prefix[i])) return "*";
    }

    sort(suffix.begin(), suffix.end(), cmp);
    for (int i = 1; i < suffix.size(); i++) {
        //cout << suffix[0] << " " << suffix[i] << endl;
        if (!end_with(suffix[0], suffix[i])) return "*";
    }

    if (prefix.size() > 0) ans = prefix.front() + ans;
    if (suffix.size() > 0) ans = ans + suffix.front();
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
