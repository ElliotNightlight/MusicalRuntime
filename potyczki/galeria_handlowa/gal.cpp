// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1111;
int n, m;
int ostatni[N];

bool odp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        ostatni[i] = 0;
    for(int i = 1; i <= n; ++i) {
        int k, p;
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            cin >> p;
            ostatni[p] = i;
        }
    }

    odp = true;
    for(int i = 1; i <= m; ++i)
        odp = odp && ostatni[i] > 0;

    if(!odp) cout << "NIE\n";
    else {
        cout << "TAK\n";
        for(int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= m; ++i)
            cout << ostatni[i] << " ";
        cout << "\n";
    }

    return 0;
}
