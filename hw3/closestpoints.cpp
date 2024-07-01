#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt(pow((a.x - b.x),2) +pow((a.y - b.y),2));
}

double closest_pair(vector<Point>& points, int l, int r) {
    if (r - l == 1) {
        return dist(points[l], points[r]);
    }
    else if(r-l==0){
        return numeric_limits<double>::infinity();
    }
    int mid = (l + r) / 2;
    double d = min(closest_pair(points, l, mid), closest_pair(points, mid + 1, r));
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    cout << fixed << setprecision(4) << closest_pair(points, 0, n - 1) << endl;
    return 0;
}
