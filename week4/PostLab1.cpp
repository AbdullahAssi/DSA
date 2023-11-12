#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y, z;
};

bool compareX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compareY(const Point &a, const Point &b) {
    return a.y < b.y;
}

bool compareZ(const Point &a, const Point &b) {
    return a.z < b.z;
}

double euclideanDistance(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

pair<Point, Point> bruteForceClosestPair(const vector<Point> &points, int start, int end) {
    pair<Point, Point> closestPair;
    double minDistance = numeric_limits<double>::infinity();

    for (int i = start; i < end; ++i) {
        for (int j = i + 1; j < end; ++j) {
            double distance = euclideanDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPair = {points[i], points[j]};
            }
        }
    }

    return closestPair;
}

pair<Point, Point> findClosestPair(const vector<Point> &points, int start, int end) {
    if (end - start <= 3) {
        return bruteForceClosestPair(points, start, end);
    }

    int mid = (start + end) / 2;

    auto leftPair = findClosestPair(points, start, mid);
    auto rightPair = findClosestPair(points, mid, end);

    pair<Point, Point> minPair = (euclideanDistance(leftPair.first, leftPair.second) < euclideanDistance(rightPair.first, rightPair.second)) ? leftPair : rightPair;

    vector<Point> strip;
    for (int i = start; i < end; ++i) {
        if (abs(points[i].z - points[mid].z) < euclideanDistance(minPair.first, minPair.second)) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < euclideanDistance(minPair.first, minPair.second); ++j) {
            double distance = euclideanDistance(strip[i], strip[j]);
            if (distance < euclideanDistance(minPair.first, minPair.second)) {
                minPair = {strip[i], strip[j]};
            }
        }
    }

    return minPair;
}

int main() {
    vector<Point> points = {
        {22, 23, 24},
        {25,26, 27},
        {31, 30, 29},
        {32, 33, 34},
        {37, 36, 35},
    };

    sort(points.begin(), points.end(), compareZ);

    auto result = findClosestPair(points, 0, points.size());

    cout << "Closest pair: (" << result.first.x << ", " << result.first.y << ", " << result.first.z << ") and ("
         << result.second.x << ", " << result.second.y << ", " << result.second.z << ")" << endl;
    cout << "Minimum distance: " << euclideanDistance(result.first, result.second) << endl;

    return 0;
}
