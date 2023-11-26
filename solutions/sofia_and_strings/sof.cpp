// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 200'000+10;
int t;
int n, m;
char src[N];
char tar[N];

vector<int> where[26];
bool answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> (src + 1);
        cin >> (tar + 1);

        for(int c = 0; c < 26; ++c)
            where[c].clear();
        for(int i = 1; i <= n; ++i) {
            int c = src[i] - 'a';
            where[c].push_back(i);
        }

        answer = true;
        for(int i = m; i >= 1; --i) {
            int c = tar[i] - 'a';
            if(where[c].size() == 0) {
                answer = false;
                break;
            }
            for(int j = c + 1; j < 26; ++j) {
                while(where[j].size() > 0
                    && where[j].back() > where[c].back())
                    where[j].pop_back();
            }
            where[c].pop_back();
        }

        if(answer) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
