#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calculateTotalDistance(const vector<Point>& route) {
    double totalDistance = 0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        totalDistance += distance(route[i], route[i + 1]);
    }
    totalDistance += distance(route.back(), route.front());  // Complete the loop
    return totalDistance;
}

vector<Point> findShortestRoute(const vector<Point>& points) {
    if (points.size() <= 3) {
        // Base case: Brute-force for small number of points
        vector<Point> route = points;
        sort(route.begin(), route.end());
        double minDistance = calculateTotalDistance(route);

        while (next_permutation(route.begin(), route.end())) {
            double currentDistance = calculateTotalDistance(route);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
            }
        }

        return route;
    }

    // Divide the set of points into two halves
    size_t mid = points.size() / 2;
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());

    // Recursively find the shortest route in each half
    vector<Point> leftRoute = findShortestRoute(left);
    vector<Point> rightRoute = findShortestRoute(right);

    // Merge the two routes
    leftRoute.insert(leftRoute.end(), rightRoute.begin(), rightRoute.end());

    // Find the shortest route that crosses the dividing line
    vector<Point> mergedRoute = leftRoute;  // Copy for modification
    inplace_merge(mergedRoute.begin(), mergedRoute.begin() + mid, mergedRoute.end(), [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
    });

    // Find the optimal route among all possibilities
    double minDistance = calculateTotalDistance(mergedRoute);
    while (next_permutation(mergedRoute.begin(), mergedRoute.end(), [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
    })) {
        double currentDistance = calculateTotalDistance(mergedRoute);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            leftRoute = mergedRoute;  // Update the optimal route
        }
    }

    return leftRoute;
}

int main() {
    int numPoints;
    cout << "Enter the number of delivery points (between 4 and 15): ";
    cin >> numPoints;

    if (numPoints < 4 || numPoints > 15) {
        cerr << "Invalid number of delivery points. Exiting.\n";
        return 1;
    }

    vector<Point> deliveryPoints;
    Point point;
    cout << "Enter the coordinates of each delivery point (x y):\n";
    for (int i = 0; i < numPoints; ++i) {
        cout << "Point " << i + 1 << ": ";
        cin >> point.x >> point.y;
        deliveryPoints.push_back(point);
    }

    vector<Point> optimalRoute = findShortestRoute(deliveryPoints);

    cout << "\nOptimal Route Indices: ";
    for (const Point& p : optimalRoute) {
        cout << &p - &optimalRoute[0] + 1 << " ";
    }

    double totalDistance = calculateTotalDistance(optimalRoute);
    cout << "\nTotal Distance Traveled: " << totalDistance << endl;

    return 0;
}
