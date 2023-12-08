// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 333'333;
int t, n;
char s[N];
int l[N], r[N];

int ans[N];
queue<int> Queue;

int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cin >> (s + 1);
        for(int u = 1; u <= n; ++u)
            cin >> l[u] >> r[u];

        ans[1] = 0;
        answer = INT32_MAX;
        Queue.push(1);
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();

            if(l[u] != 0) {
                ans[l[u]] = ans[u];
                if(s[u] != 'L') ++ans[l[u]];
                Queue.push(l[u]);
            }

            if(r[u] != 0) {
                ans[r[u]] = ans[u];
                if(s[u] != 'R') ++ans[r[u]];
                Queue.push(r[u]);
            }

            if(l[u] == 0 && r[u] == 0)
                answer = min(answer, ans[u]);
        }

        cout << answer << "\n";
    }

    return 0;
}
