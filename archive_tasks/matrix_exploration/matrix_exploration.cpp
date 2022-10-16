#include <bits/stdc++.h> // Includes all the standard libraries (iostream, vector, algorythm...)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

// https://csacademy.com/contest/archive/task/matrix_exploration/

int n, m, k;

struct cell {
    char type;
    int distance;
    bool visited;
};

void print_matrix_symbol(vector<vector<cell>> matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j].type;
        }
        cout << endl;
    }
}

void print_matrix_distance(vector<vector<cell>> matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j].distance << " ";
        }
        cout << endl;
    }
}

int sum_of_distances(vector<vector<cell>> matrix) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j].distance;
        }
    }
    return sum;
}

int main(){

    // Making input and output faster
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    vector<vector<cell>> matrix(n, vector<cell>(m));
    vector<pii> start_points(k);

    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            matrix[i][j].type = temp;
            matrix[i][j].distance = 0;
            if (temp == '#'){
                matrix[i][j].visited = true;
            } else {
                matrix[i][j].visited = false;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> start_points[i].first >> start_points[i].second;
        start_points[i].first--;
        start_points[i].second--;
    }

    for (auto p : start_points){
        matrix[p.first][p.second].type = '*';
        matrix[p.first][p.second].visited = true;
    }

    //print_matrix_symbol(matrix);

    queue<pair<int,int>> q;
    for (auto p : start_points){
        q.push(p);
    }

    while (!q.empty()){
        pii p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x > 0 && !matrix[x-1][y].visited){
            matrix[x-1][y].visited = true;
            matrix[x-1][y].distance = matrix[x][y].distance + 1;
            q.push(make_pair(x-1, y));
        }
        if (x < n-1 && !matrix[x+1][y].visited){
            matrix[x+1][y].visited = true;
            matrix[x+1][y].distance = matrix[x][y].distance + 1;
            q.push(make_pair(x+1, y));
        }
        if (y > 0 && !matrix[x][y-1].visited){
            matrix[x][y-1].visited = true;
            matrix[x][y-1].distance = matrix[x][y].distance + 1;
            q.push(make_pair(x, y-1));
        }
        if (y < m-1 && !matrix[x][y+1].visited){
            matrix[x][y+1].visited = true;
            matrix[x][y+1].distance = matrix[x][y].distance + 1;
            q.push(make_pair(x, y+1));
        }
    }

    //print_matrix_distance(matrix);
    cout << sum_of_distances(matrix) << endl;


    return 0;
}