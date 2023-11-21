// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t, n;
int a[N];
long long sum_prefix[N];
long long sum_suffix[N];
long long min_prefix[N];
long long min_suffix[N];
long long answer;

inline bool ok(int x, int y) {
    return (bool) ((x - y) % 2 != 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        for(int i = 1; i <= n; ++i) {
            if(i == 1 || !ok(a[i], a[i-1])) {
                sum_prefix[i] = a[i];
                min_prefix[i] = min(a[i], 0);
            } else {
                sum_prefix[i] = sum_prefix[i-1] + a[i];
                min_prefix[i] = min(min_prefix[i-1], sum_prefix[i]);
            }
        }

        for(int i = n; i >= 1; --i) {
            if(i == n || !ok(a[i], a[i+1])) {
                sum_suffix[i] = a[i];
                min_suffix[i] = min(a[i], 0);
            } else {
                sum_suffix[i] = sum_suffix[i+1] + a[i];
                min_suffix[i] = min(min_suffix[i+1], sum_suffix[i]);
            }
        }

        answer = INT64_MIN;
        for(int i = 1; i <= n; ++i) {
            long long ans1 = a[i];
            if(i != 1 && ok(a[i], a[i-1])) {
                ans1 += sum_prefix[i-1];
                ans1 -= min_prefix[i-1];
            }
            if(i != n && ok(a[i], a[i+1])) {
                ans1 += sum_suffix[i+1];
                ans1 -= min_suffix[i+1];
            }
            answer = max(answer, ans1);
        }

        cout << answer << '\n';
    }

    return 0;
}
