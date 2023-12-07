// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1'111'111;
int t, n;
char a[N];
char b[N];

int constexpr M = 998'244'353;
struct Q {
    int p;
    int q;
    Q(int p = 0, int q = 1) : p(p), q(q) {}
    operator int() const {
        // relying on the fact that M is prime
        int ans = p;
        int qq = q;
        int k = M - 2;
        while(k > 0) {
            if(k % 2) ans = (long long) ans * qq % M;
            qq = (long long) qq * qq % M;
            k /= 2;
        }
        return ans;
    }
};
Q operator+(Q x, Q y) {
    return Q (
        ((long long) x.p * y.q + (long long) y.p * x.q) % M,
        (long long) x.q * y.q % M
    );
}
Q operator*(Q x, Q y) {
    return Q (
        (long long) x.p * y.p % M,
        (long long) x.q * y.q % M
    );
}

Q c[N];
Q ans[N];
int good;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cin >> (a + 1);
        cin >> (b + 1);

        c[0] = Q(1, 1);
        for(int i = 0; i <= n-2; ++i) {
            c[i+1] = c[i] * Q(i+1, n-i-1) + Q(n, n-i-1);
        }

        ans[n] = 0;
        for(int i = n-1; i >= 0; --i) {
            ans[i] = ans[i+1] + c[i];
        }

        good = 0;
        for(int j = 1; j <= n; ++j) {
            if(a[j] == b[j])
                ++good;
        }

        cout << (int) ans[good] << "\n";
    }

    return 0;
}
