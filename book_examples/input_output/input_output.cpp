#include <bits/stdc++.h> // Includes all the standard libraries (iostream, vector, algorythm...)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

int main(){

    // Making input and output faster
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (freopen("input.txt", "r", stdin) == NULL){
        cout << "Error opening input file" << endl;
        return 0;
    }

    if (freopen("output.txt", "w", stdout) == NULL){
        cout << "Error opening output file" << endl;
        return 0;
    }

    int a, b;
    string s;

    cin >> a >> s >> b;
    cout << a << " " << s << " " << b << endl;

    return 0;
}