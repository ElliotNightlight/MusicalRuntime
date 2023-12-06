// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 111'111;
int t;
int n, k;
int a[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        ans = k - 1;
        for(int i = 1; i <= n; ++i)
            ans = min((k * 100 - a[i]) % k, ans);

        if(k == 4) {
            int e = 0;
            for(int i = 1; i <= n; ++i)
                if(a[i] % 2 == 0)
                   ++e;
            if(e >= 2) ans = 0;
            else if(e == 1) ans = min(ans, 1);
            else ans = min(ans, 2);
        }

        cout << ans << "\n";
    }

    return 0;
}
