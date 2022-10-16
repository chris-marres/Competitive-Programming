#include <bits/stdc++.h> // Includes all the standard libraries (iostream, vector, algorythm...)
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

// https://csacademy.com/contest/archive/task/sorting_partition/


int main(){

    // Making input and output faster
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int current = 0;
    int temp = 0;
    int count = 1;

    cin >> current;
    for (int i = 0; i < n-1; i++){
        cin >> temp;
        if (temp >= current){
            count++;
            current = temp;
        }
    }

    cout << count << endl;

    return 0;
}