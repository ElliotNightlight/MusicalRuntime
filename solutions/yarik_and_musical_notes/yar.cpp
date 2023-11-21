// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t, n;
int a[N];
long long answer;
int ones, twos;
int C;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        ones = 0, twos = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 1) ++ones;
            else if(a[i] == 2) ++twos;
        }
        answer = (long long) ones * twos;

        sort(&a[1], &a[n]+1);
        for(int i = 1; i <= n; ++i) {
            if(i == 1 || a[i] != a[i-1]) C = 1;
            else {
                answer += C;
                C++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
