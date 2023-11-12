#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <float.h>

using namespace std;

struct Point {
    int x, y, z;
};

bool compareZ(Point a, Point b) { 
    return a.z < b.z; 
    }

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

pair<Point, Point> closestPair(vector<Point> points) {
    sort(points.begin(), points.end(), compareZ);

    double minDist = DBL_MAX;
    pair<Point, Point> closestPair;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size() && (points[j].z - points[i].z) < minDist; j++) {
            if (distance(points[i], points[j]) < minDist) {
                minDist = distance(points[i], points[j]);
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

int main() {
    vector<Point> points = {
        {22, 23, 24},
        {25,26, 27},
        {31, 30, 29},
        {32, 33, 34},
        {37, 36, 35},
        };
    pair<Point, Point> result = closestPair(points);

    cout<< "Closest pair: (" << result.first.x << ", " << result.first.y << ", " << result.first.z << ") and ("
        << result.second.x << ", " << result.second.y << ", " << result.second.z << ")" << endl;
    cout<< "Minimum distance: " << distance(result.first, result.second) << endl;

    return 0;
}