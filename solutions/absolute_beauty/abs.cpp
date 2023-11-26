// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t, n;
int a[N], b[N];
int MinRight, MaxLeft;
long long answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            cin >> b[i];

        MinRight = INT32_MAX;
        MaxLeft = INT32_MIN;
        answer = 0;
        for(int i = 1; i <= n; ++i) {
            int Left, Right;
            if(a[i] < b[i]) { Left = a[i]; Right = b[i]; }
            else { Left = b[i]; Right = a[i]; }
            MinRight = min(MinRight, Right);
            MaxLeft = max(MaxLeft, Left);
            answer += Right - Left;
        }

        if(MaxLeft > MinRight)
            answer += 2 * (MaxLeft - MinRight);
        cout << answer << '\n';
    }

    return 0;
}
