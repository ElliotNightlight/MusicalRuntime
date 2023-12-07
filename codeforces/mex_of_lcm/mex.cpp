// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 333'333;
int constexpr K = 30; // assuming prefix LCM has at most K unique values
int t, n;
int a[N];
vector<int> sth;
int ANS; // the answer is at most ANS = n * K + 1
bool ans[N * K];
int the_answer_itself;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        sth.clear();
        ANS = n * K + 1;
        for(int i = 1; i <= ANS; ++i)
            ans[i] = false;

        for(int i = n; i >= 1; --i) {
            vector<int> sth_else;
            if(a[i] <= ANS) {
                sth_else.push_back(a[i]);
                ans[a[i]] = true;
            }
            for(long long x : sth) {
                x = lcm(x, (long long) a[i]);
                if(x > ANS) continue;
                if(x == sth_else.back()) continue;
                sth_else.push_back(x);
                ans[x] = true;
            }

            sth.swap(sth_else);
        }

        the_answer_itself = ANS;
        for(int i = 1; i <= ANS; ++i) {
            if(!ans[i]) {
                the_answer_itself = i;
                break;
            }
        }

        cout << the_answer_itself << "\n";
    }

    return 0;
}
