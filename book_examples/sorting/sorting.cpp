#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

void printVector(vi &v){
    for (long unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printPairVector(vector<pii> &v){
    for (long unsigned int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << endl;
    cout << endl;
}

void printTupleVector(vector<tuple<int, int, int>> &v){
    for (long unsigned int i = 0; i < v.size(); i++)
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << endl;
    cout << endl;
}


struct point {
    int x, y;
    bool operator<(const point &p) {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

void printPointVector(vector<point> &v){
    for (long unsigned int i = 0; i < v.size(); i++)
        cout << v[i].x << " " << v[i].y << endl;
    cout << endl;
}
   

int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    // Sorting Vectors
    cout << "Sorting Vectors" << endl;
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    cout << "Before sorting: ";
    printVector(v);
    sort(v.begin(), v.end());
    cout << "After sorting: ";
    printVector(v);
    cout << "Sort in the reverse order: ";
    sort(v.rbegin(), v.rend());
    printVector(v);
    cout << endl;

    // Sorting Arrays
    cout << "Sorting Arrays" << endl;
    int size = 7;
    int arr[] = {4, 2, 5, 3, 5, 8, 3};
    sort(arr, arr + 7);
    cout << "After sorting: ";
    printArray(arr, size);
    cout << endl;

    // Sorting strings
    cout << "Sorting strings" << endl;
    string s = "hello";
    sort(s.begin(), s.end());
    cout << "After sorting: " << s << endl;
    cout << endl;

    // Sorting pairs
    cout << "Sorting pairs" << endl;
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {2, 3}, {4, 5}, {3, 6}};
    cout << "Before sorting: " << endl;
    printPairVector(vp);
    sort(vp.begin(), vp.end());
    cout << "After sorting: " << endl;
    printPairVector(vp);
    cout << endl;

    // Sorting tuples
    cout << "Sorting tuples" << endl;
    vector<tuple<int, int, int>> vt = {{1, 2, 3}, {3, 4, 5}, {2, 3, 4}, {4, 5, 6}, {3, 6, 7}};
    cout << "Before sorting: " << endl;
    printTupleVector(vt);
    sort(vt.begin(), vt.end());
    cout << "After sorting: " << endl;
    printTupleVector(vt);
    cout << endl;


    // Sorting structs
    cout << "Sorting structs" << endl;
    vector<point> pv = {{1, 2}, {3, 4}, {2, 3}, {4, 5}, {3, 6}};
    cout << "Before sorting: " << endl;
    printPointVector(pv);
    sort(pv.begin(), pv.end());
    cout << "After sorting: " << endl;
    printPointVector(pv);
    cout << endl;



    return 0;
}
