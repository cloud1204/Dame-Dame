#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fi first
#define se second
#define mat vector<vector<ll>> 
using namespace std;
void db() {cout << '\n';}
template <typename T, typename ...U> void db(T a, U ...b) {cout << a << ' ', db(b...);}

#define file ios::sync_with_stdio(false); cin.tie(0)

const int N = 1e5 + 1, mod = 998244353, inf = 1ll << 60;
signed main(){
    file;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> banned[n];
    map<string, bool> has;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if (has[s]) continue;
        has[s] = 1;
        int a = s[0] - 'a', b = s[1] - 'a', c = s[2] - 'a';
        banned[b].push_back({a, c});
    }
    bool bad[1 << n][n];
    for (int x = 0; x < n; x++){
        int dp[1 << n]{};
        for (auto i : banned[x]){
            dp[1 << i.fi]++;
            dp[(1 << i.fi) + (1 << i.se)]--;
        }
        for (int i = 0; i < n; i++){
            for (int msk = 0; msk < (1 << n); msk++){
                if (msk >> i & 1) dp[msk] += dp[msk ^ (1 << i)];
            }
        }
        for (int i = 0; i < (1 << n); i++) bad[i][x] = (dp[i] > 0);
    }
    int dp[1 << n][n]{};
    for (int msk = 0; msk < (1 << n); msk++){
        for (int c = 0; c < n; c++){
            if (!(msk >> c & 1)) continue;
            if (bad[msk][c]) continue;
            if (__builtin_popcount(msk) == 1){
                dp[msk][c] = 1;
                continue;
            }
            for (int pc = 0; pc < n; pc++){
                if (pc == c or !(msk >> pc & 1)) continue;
                dp[msk][c] += dp[msk - (1 << c)][pc];
            }
        }
    }
    int ans = 0;
    int facn = 1;
    for (int i = 1; i <= n; i++) facn *= i;
    for (int i = 0; i < n; i++) ans += dp[(1 << n) - 1][i];
    cout << facn - ans << '\n';
}

