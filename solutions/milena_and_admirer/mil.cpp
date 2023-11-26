// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t, n;
int a[N];

int constexpr INF = 1'000'000'000;
int Bound;
long long answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        Bound = INF;
        answer = 0;
        for(int i = n; i >= 1; --i) {
            int k = (a[i] + Bound - 1) / Bound;
            answer += k - 1;
            Bound = a[i] / k;
        }

        cout << answer << '\n';
    }

    return 0;
}
