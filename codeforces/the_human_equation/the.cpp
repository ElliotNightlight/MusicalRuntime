// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int t, n;
int a[N];
long long positive_ending; // *positive_ending* = number of available sequences whose last element was *plus one*
long long negative_ending; // *negative_ending* = number of available sequences whose last element was *minus one*

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        positive_ending = 0;
        negative_ending = 0;
        for(int i = 1; i <= n; ++i) {
            int x = a[i];
            if(x > 0) {
                positive_ending -= x;
                if(positive_ending < 0) positive_ending = 0;
                negative_ending += x;
            } else if(x < 0) {
                x *= -1;
                negative_ending -= x;
                if(negative_ending < 0) negative_ending = 0;
                positive_ending += x;
            }
        }

        cout << positive_ending + negative_ending << "\n";
    }

    return 0;
}
