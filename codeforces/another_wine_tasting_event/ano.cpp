// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2'222'222;
int n;
char s[N];
int white[N];
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> (s + 1);

    white[0] = 0;
    for(int i = 1; i <= 2*n-1; ++i) {
        white[i] = white[i-1];
        if(s[i] == 'W') ++white[i];
    }

    answer = INT32_MIN;
    for(int i = 1; i <= n; ++i) {
        answer = max(white[i+n-1]-white[i-1], answer);
    }
    cout << answer << "\n";

    return 0;
}
