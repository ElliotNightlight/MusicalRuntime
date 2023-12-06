// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int t;
int k, n;
char s[N];
int C[26];

int ones;
int evens;

bool ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> (s + 1);
        for(int i = 0; i != 26; ++i) C[i] = 0;
        for(int i = 1; i <= n; ++i) C[s[i] - 'a'] += 1;

        ones = 0;
        evens = 0;
        for(int i = 0; i != 26; ++i) {
            ones += C[i] % 2;
            evens += C[i] / 2 * 2;
        }

        ans = k + 1 >= ones;
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
