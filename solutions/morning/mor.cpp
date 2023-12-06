// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int t;
char s[10];
int curr, last;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> (s + 1);
        last = 1;
        ans = 4;
        for(int i = 1; i <= 4; ++i) {
            curr = s[i] - '0';
            if(curr == 0) curr = 10;
            ans += abs(last - curr);
            last = curr;
        }
        cout << ans << "\n";
    }

    return 0;
}
