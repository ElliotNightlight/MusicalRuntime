// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int t, n;
int a[N];
long long css; // conditional suffix sum - css = sum of positive a[j] with j > i for sum i in the for loop
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        css = 0;
        ans = 0;
        for(int i = n; i >= 1; --i) {
            if(i % 2 == 0) ans = max(ans, css);
            else ans = max(ans, css + a[i]);

            if(a[i] > 0)
                css += a[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
