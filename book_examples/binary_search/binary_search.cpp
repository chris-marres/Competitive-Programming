#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

// lower_bound returs a pointer to the first array element whose value is at least x

// upper_bound returns a pointer to the first array element whose vallue is larger than x

// equal_range returns both above pointers

// all the above functions assume that the array is sorted obviously


int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    vi v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto k = lower_bound(v.begin(), v.end(), 5);
    cout << *k << endl;
    *k = 100;
    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}
