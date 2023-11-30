// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int t;
int n, x;
pair<int,int> a[N];
int b[N];
pair<int,int> c[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 1; i <= n; ++i) cin >> b[i];

        sort(&a[1], &a[n]+1);
        sort(&b[1], &b[n]+1);

        for(int i = 1; i <= n - x; ++i)
            c[i].second = b[i + x];
        for(int i = n - x + 1; i <= n; ++i)
            c[i].second = b[i - (n - x)];

        ans = 0;
        for(int i = 1; i <= n; ++i) {
            c[i].first = a[i].second;
            if(a[i].first > c[i].second) ++ans;
        }

        if(ans == x) {
            cout << "yes\n";
            sort(&c[1], &c[n]+1);
            for(int i = 1; i <= n; ++i)
                cout << c[i].second << ' ';
            cout << '\n';
        } else cout << "no\n";


// 1 2 3 4 5 6 7 8
// 3 4 5 6 7 8 1 2
    }

    return 0;
}
