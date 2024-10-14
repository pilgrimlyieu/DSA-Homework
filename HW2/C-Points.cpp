#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

double distance(const Point& a, const Point& b) {
    // int 范围老是没考虑到……几道题都因为这个卡了几次。反而是最后一题不用考虑，错了第一反应是去考虑……
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool compare_x(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compare_y(const Point& a, const Point& b) {
    return a.y < b.y;
}

double closest_pair(vector<Point>& points, int left, int right) {
    if (left == right) {
        return 1e20;
    }
    if (left + 1 == right) {
        return distance(points[left], points[right]);
    }
    int mid = (left + right) / 2;
    double d = min(closest_pair(points, left, mid), closest_pair(points, mid + 1, right));
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - points[mid].x) <= d) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), compare_y);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < d; j++) {
            d = min(d, distance(strip[i], strip[j]));
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
    sort(points.begin(), points.end(), compare_x);
    cout << fixed << setprecision(4) << closest_pair(points, 0, n - 1) << endl;
    return 0;
}