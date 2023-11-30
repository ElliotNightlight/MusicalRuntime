// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 100'000+10;
int t;
int n, q;
set<int> where_are_ones;
int sum;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        where_are_ones.clear();
        sum = 0;
        for(int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            if(a == 1)
                where_are_ones.insert(i);
            sum += a;
        }

        while(q--) {
            char c;
            cin >> c;
            if(c == '1') {
                int s;
                cin >> s;
                if(where_are_ones.size() == 0) {
                    if(s % 2 == 0) cout << "yes\n";
                    else cout << "no\n";
                } else {
                    int leading_twos = *where_are_ones.begin() - 1;
                    int trailing_twos = n - *where_are_ones.rbegin();
                    int core = sum - 2 * min(leading_twos, trailing_twos);
                    if(s <= core) cout << "yes\n";
                    else {
                        if((s - core) % 2 == 0 && s <= sum) cout << "yes\n";
                        else cout << "no\n";
                    }
                }
            } else {
                int i, v;
                cin >> i >> v;
                if(where_are_ones.count(i)) sum -= 1;
                else sum -= 2;
                where_are_ones.erase(i);
                if(v == 1)
                    where_are_ones.insert(i);
                sum += v;
            }

            /*cout << " ";
            for(int i = 1; i <= n; ++i) {
                if(where_are_ones.count(i)) cout << "1 ";
                else cout << "2 ";
            }
            cout << "\n";
            cout << " ";
            for(int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << "\n";*/
        }
    }

    return 0;
}
