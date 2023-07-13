#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, bool> has;
    vector<string> banned;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if (has[s]) continue;
        has[s] = 1;
        banned.push_back(s);
    }
    vector<char> v;
    for (int i  = 0; i < n; i++) {
        v.push_back(char('a' + i));
    }
    auto check = [&](vector<char> v){
        for (string s : banned){
            int ptr = 0;
            for (int i = 0; i < n; i++){
                if (ptr < 3 and s[ptr] == v[i]) ptr++;
            }
            if (ptr >= 3) {
                /*
                for (char i : v){
                    cout << i;
                }
                cout << '\n';
                */
                return 0;
            }
        }
        return 1;
    };
    int facn = 1;
    for (int i = 1; i <= n; i++) facn *= i;
    int ans = check(v);
    while (next_permutation(v.begin(), v.end())){
        ans += check(v);
    }
    cout << facn - ans << '\n';
}
