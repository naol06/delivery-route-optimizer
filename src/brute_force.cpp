#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include "point.h"

double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(const std::vector<Point>& points, int left, int right) {
    double minDist = std::numeric_limits<double>::max();
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minDist = std::min(minDist, calculateDistance(points[i], points[j]));
        }
    }
    return minDist;
}
