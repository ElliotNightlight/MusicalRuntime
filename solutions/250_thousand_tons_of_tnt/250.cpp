// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 150'000+20;
int t, n;
int a[N];
long long sum[N];

long long ans;
long long truck_maximum;
long long truck_minimum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        sum[0] = 0;
        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + a[i];

        ans = 0;
        for(int k = 1; k <= n; ++k) {
            if(n % k) continue;
            truck_maximum = INT64_MIN;
            truck_minimum = INT64_MAX;
            for(int j = 1; j <= n / k; ++j) {
                long long weight = sum[j * k] - sum[(j-1) * k];
                truck_maximum = max(truck_maximum, weight);
                truck_minimum = min(truck_minimum, weight);
            }
            ans = max(ans, truck_maximum - truck_minimum);
        }

        cout << ans << '\n';
    }

    return 0;
}
