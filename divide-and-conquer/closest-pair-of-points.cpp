#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Point {
    public:
    int x, y;
};

bool compare_x(Point p1, Point p2) {
    return (p1.x < p2.x)? p1 : p2;
}

bool compare_y(Point p1, Point p2) {
    return (p1.y < p2.y)? p1 : p2;
}

float distance(Point p1, Point p2) {
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

float bruteforce(Point P[], int n) {
    float_min = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (distance(P[i], P[j]) < float_min)
                float_min = distance(P[i], P[j]);
        }
    }

    return float_min;
}

float strip_closest(Point strip[], int n, int d) {
    int min_d = d;

    sort(strip, strip + n, compare_y);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && ((strip[j].y - strip[j].y) < min_d); j++) {
            if (distance(strip[i], strip[j]) < min_d)
                min_d = distance(strip[i], strip[j]);
        }
    }

    return min_d;
}

float closest_util(Point P[], int n) {
    if (n <= 3)
        return bruteforce(P, n);

    int mid = n/2;
    Point midpoint = P[mid];

    int minl = closest_util(P, mid);
    int minr = closest_util(P + mid, n - mid);

    int d = min(minl, minr);

    Point strip[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - midpoint.x) < d) {
            strip[i] = P[i];
            j++;
        }
    }

    return min(d, strip_closest(strip, j, d));
}

float closest(Point P[], int n) {
    sort(P, P+n, compare_x);

    return closest_util(P, n);
}

int main(int argc, char ** argv) {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P)/sizeof(P[0]);

    cout << closest(P, n);
}
