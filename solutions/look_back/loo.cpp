// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 111'111;
int t, n;
int a[N];
pair<double, long long> l[N];
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) {
            l[i] = make_pair((double) a[i], (long long) 0);
            while(l[i].first >= 2) {
                l[i].first = l[i].first / 2;
                l[i].second++;
            }
        }

        ans = 0;
        for(int i = 2; i <= n; ++i) {
            if(l[i - 1].second < l[i].second) continue;

            ans += l[i - 1].second - l[i].second;
            l[i].second = l[i - 1].second;

            if(l[i].first < l[i - 1].first) {
                l[i].second++;
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
