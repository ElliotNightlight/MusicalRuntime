// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        if(n % 3) cout << "First\n";
        else cout << "Second\n";
    }

    return 0;
}
