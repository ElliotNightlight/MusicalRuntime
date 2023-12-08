// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 111;
int t;
int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if(b % 2 == c % 2) cout << "1 "; else cout << "0 ";
        if(c % 2 == a % 2) cout << "1 "; else cout << "0 ";
        if(a % 2 == b % 2) cout << "1\n"; else cout << "0\n";
    }

    return 0;
}
