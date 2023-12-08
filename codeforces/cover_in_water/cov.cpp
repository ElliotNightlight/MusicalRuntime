// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 111;
int t, n;
char s[N];
bool infinite_water_glitch;
int C;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cin >> (s + 1);
        ans = 0;
        C = 0;
        infinite_water_glitch = false;
        for(int i = 1; i <= n; ++i) {
            switch(s[i]) {
            case '.': C++; ans++; break;
            case '#': if(C > 2) infinite_water_glitch = true; C = 0; break;
            }
        }
        if(C > 2) infinite_water_glitch = true;
        if(infinite_water_glitch) ans = min(ans, 2);
        cout << ans << "\n";
    }

    return 0;
}
