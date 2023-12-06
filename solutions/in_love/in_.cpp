// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int q;
struct Interval { int l, r; };
struct alpha_cmp { bool operator() (Interval I, Interval J) const { return I.r < J.r; } };
struct beta_cmp { bool operator() (Interval I, Interval J) const { return I.l < J.l; } };

multiset<Interval, alpha_cmp> A;
multiset<Interval, beta_cmp> B;
bool answer;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while(q--) {
        char c;
        Interval I;
        cin >> c >> I.l >> I.r;
        if(c == '-') {
            A.erase(A.lower_bound(I));
            B.erase(B.lower_bound(I));
        } else {
            A.insert(I);
            B.insert(I);
        }

        //for(const Interval I : A) cout << I.l << " " << I.r << " | "; cout << "\n";
        //for(const Interval I : B) cout << I.l << " " << I.r << " | "; cout << "\n";

        if(A.size() >= 2) answer = A.begin()->r < B.rbegin()->l;
        else answer = false;
        if(answer) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
