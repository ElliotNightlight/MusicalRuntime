// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 500+10;
int t, n, q, d;
int att;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;

        for(int i = 1; i <= n-1; ++i)
            cout << i << ' ' << i + 1 << '\n';
        att = n-1;

        while(q--) {
            cin >> d;

            if(att == d) cout << "-1 -1 -1\n";
            else {
                cout << n << ' ' << att << ' ' << d << '\n';
                att = d;
            }
        }
    }

    return 0;
}
