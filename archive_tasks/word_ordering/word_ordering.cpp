#include <bits/stdc++.h> // Includes all the standard libraries (iostream, vector, algorythm...)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

map<char, int> m;

struct my_string {
    string s;
    bool operator<(const my_string& rhs) const {
        size_t i = 0;
        while (i < s.size() && i < rhs.s.size()) {
            if (m[s[i]] < m[rhs.s[i]]) {
                return true;
            } else if (m[s[i]] > m[rhs.s[i]]) {
                return false;
            }
            i++;
        }
        return s.size() < rhs.s.size();
    }
};

int main(){

    // Making input and output faster
    ios::sync_with_stdio(0);
    cin.tie(0);

    string permutation;
    cin >> permutation;

    for (size_t i = 0; i < permutation.size(); i++) {
        m[permutation[i]] = i;
        m[permutation[i]-32] = i + 26;
    }

    int n;
    cin >> n;

    vector<my_string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i].s;
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < n; i++) {
        cout << words[i].s << endl;
    }

    return 0;
}