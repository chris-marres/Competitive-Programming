#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define pb push_back

// https://csacademy.com/contest/archive/task/points_in_polygon/

struct point {
    float x, y;
    point(float x, float y) : x(x), y(y) {}
};

struct segment {
    point a, b;
    segment(point a, point b) : a(a), b(b) {}
};

bool segment_intersection (segment s1, segment s2) {
    float d1 = (s1.b.x - s1.a.x) * (s2.a.y - s1.a.y) - (s1.b.y - s1.a.y) * (s2.a.x - s1.a.x);
    float d2 = (s1.b.x - s1.a.x) * (s2.b.y - s1.a.y) - (s1.b.y - s1.a.y) * (s2.b.x - s1.a.x);
    float d3 = (s2.b.x - s2.a.x) * (s1.a.y - s2.a.y) - (s2.b.y - s2.a.y) * (s1.a.x - s2.a.x);
    float d4 = (s2.b.x - s2.a.x) * (s1.b.y - s2.a.y) - (s2.b.y - s2.a.y) * (s1.b.x - s2.a.x);
    return ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0));
}

bool point_segment_intersection (point p, segment s) {
    return (p.x - s.a.x) * (s.b.y - s.a.y) == (p.y - s.a.y) * (s.b.x - s.a.x) &&
           min(s.a.x, s.b.x) <= p.x && p.x <= max(s.a.x, s.b.x) &&
           min(s.a.y, s.b.y) <= p.y && p.y <= max(s.a.y, s.b.y);
}

int main() {

    // Make the input and output more efficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<point> polygon;
    int temp1, temp2;
    int max_x = 0, max_y = 0, min_x = INT_MAX, min_y = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        if (temp1 > max_x) max_x = temp1;
        if (temp2 > max_y) max_y = temp2;
        if (temp1 < min_x) min_x = temp1;
        if (temp2 < min_y) min_y = temp2;
        polygon.pb(point(temp1, temp2));
    }

    vector<point> points;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        points.pb(point(temp1, temp2));
    }

    vector<segment> segments;
    for (int i = 0; i < n; i++) {
        segments.pb(segment(polygon[i], polygon[(i + 1) % n]));
    }

    int result = 0;

    for (int i = 0; i < m; i++) {
        int intersections = 0;
        for (int j = 0; j < n; j++) {
            if (points[i].x > max_x || points[i].x < min_x || points[i].y > max_y || points[i].y < min_y) {
                break;
            }
            if (point_segment_intersection(points[i], segments[j])) {
                intersections = 3;
                break;
            }
            if (segment_intersection(segment(points[i], point(-1, points[i].y+0.01)), segments[j])) {
                intersections++;
            }
        }
        if (intersections % 2 == 1) {
            result++;
        }
    }
    
    cout << result << endl;

    return 0;
}
