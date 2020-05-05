#include <iostream>
#include <string>
using namespace std;

string solve() {
    string str;
    cin >> str;
    for (int i = 9; i > 0; i--) {
        string t;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(' || str[j] == ')' || str[j] < i + '0') {
                t += str[j];
                continue;
            }
            int k = j;
            while (k + 1 < str.length() && 
                  (str[k + 1] == '(' || str[k + 1] == ')' || str[k + 1] >= i + '0')) k++;
            t += "(" + str.substr(j, k - j + 1) + ")";
            j = k;
        }
        swap(t, str);
    }
    return str;
}

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        string ans = solve();
        cout << "Case #" << Case++ << ": " << ans << endl;
    }
    return 0;
}
