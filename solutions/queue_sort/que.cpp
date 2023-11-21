// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t, n;
int a[N];

int best; // index of the element that is important to us
bool ok; // whether it is even possible to sort

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        for(int i = 1; i <= n; ++i) {
            if(i == 1 || a[i] < a[best]) {
                best = i;
                ok = true;
            } else {
                ok = ok && a[i] >= a[i-1];
            }
        }

        if(!ok) cout << "-1\n";
        else cout << best - 1 << '\n';
    }

    return 0;
}
