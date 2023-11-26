// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t, n;
int least, greatest;
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        least = INT32_MAX;
        greatest = INT32_MIN;
        for(int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            least = min(least, a);
            greatest = max(greatest, a);
        }

        answer.clear();
        while(greatest - least > 0) {
            int x;
            if(least % 2 == 1) x = 1;
            else x = 0;
            answer.push_back(x);
            least = (least + x) / 2;
            greatest = (greatest + x) / 2;
        }

        cout << (int) answer.size() << '\n';
        if((int) answer.size() <= n) {
            for(int x : answer)
                cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}
