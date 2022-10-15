#include <bits/stdc++.h>
using namespace std;

int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    double x = 0.3*3 + 0.1;
    double y = 1.0;
    printf("y = %.20f\n", y);
    printf("x = %.20f\n", x); // => 0.99999999999999988898
    printf("test with == : ");
    if (x == y) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }
    printf("test with abs : ");
    if (abs(x - 1.0) < 1e-9) printf("Equal\n");

    return 0;
}