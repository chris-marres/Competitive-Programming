#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x = 9 * 1e18;
    cout << x << "\n";

    vvi v;

    for (int i = 0; i < 10; i++) {
        vi temp;
        for (int j = 0; j < 10; j++) {
            temp.pb(i*10 + j);
        }
        v.pb(temp);
    }

    for (auto p : v) {
        for (auto x : p) {
            cout << x << "\n";
        }
    }

    return 0;
}
