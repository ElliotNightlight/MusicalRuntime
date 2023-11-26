// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 40'000+10;
int t, n;
struct X {
    int index;
    int alpha, beta;
} x[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            x[i].index = i;
            cin >> x[i].alpha;
        }

        sort(&x[1], &x[n] + 1, [](X p, X q)->bool { return p.alpha < q.alpha; });

        for(int i = 1; i <= n; ++i)
            x[i].beta = n + 1 - i;

        sort(&x[1], &x[n] + 1, [](X p, X q)->bool { return p.index < q.index; });

        for(int i = 1; i <= n; ++i)
            cout << x[i].beta << ' ';
        cout << '\n';
    }

    return 0;
}
