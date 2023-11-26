// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 20;
int t;
int n, m, k;
bool ans;
char horizontal[N][N];
char vertical[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        if(k < (n - 1) + (m - 1)
        || k % 2 != ((n - 1) + (m - 1)) % 2) {
            cout << "no\n";
        } else {
            cout << "yes\n";

            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m-1; ++j)
                    horizontal[i][j] = 'B';
            for(int i = 1; i <= n-1; ++i)
                for(int j = 1; j <= m; ++j)
                    vertical[i][j] = 'R';
            for(int i = 1; i <= n-1; ++i) {
                if((i + 1) % 2 == 0) vertical[i][1] = 'B';
                else vertical[i][1] = 'R';
            }
            for(int j = 1; j <= m-1; ++j) {
                int i = n;
                if((i + j) % 2 == 0) horizontal[i][j] = 'B';
                else horizontal[i][j] = 'R';
            }

            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m-1; ++j)
                    cout << horizontal[i][j] << ' ';
                cout << '\n';
            }
            for(int i = 1; i <= n-1; ++i) {
                for(int j = 1; j <= m; ++j)
                    cout << vertical[i][j] << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}
