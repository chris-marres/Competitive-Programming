#include <bits/stdc++.h>
using namespace std;

int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int array[8] = {-1, 2, 4, -3, 5, 2, -5, 2};

    int best = 0, sum = 0;

    for (int i = 0; i < 8; i++) {
        sum = max(array[i], sum + array[i]);
        best = max(best, sum);
    }

    cout << best << "\n";

    return 0;
}
