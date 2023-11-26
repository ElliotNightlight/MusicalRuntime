// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 3e5+10;
int n;
int a[N];
int l[N], r[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        l[i] = (n - 1) - (i - 1) + a[i];
        r[i] = (n - 1) - (n - i) + a[i];
    }

    for(int i = 2; i <= n; ++i)
        l[i] = max(l[i-1], l[i]);
    for(int i = n-1; i >= 1; --i)
        r[i] = max(r[i+1], r[i]);

    ans = INT32_MAX;
    for(int i = 1; i <= n; ++i) {
        int p = INT32_MIN;
        if(i != 1) p = max(p, l[i-1]);
        if(i != n) p = max(p, r[i+1]);
        p = max(p, a[i]);
        ans = min(ans, p);
    }

    cout << ans << '\n';

    return 0;
}
