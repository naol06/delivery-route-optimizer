#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double closest_pair_helper(std::vector<std::pair<int, int>>& points) {
    double min_dist = std::numeric_limits<double>::max();
    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            min_dist = std::min(min_dist, distance(points[i].first, points[i].second, points[j].first, points[j].second));
        }
    }
    return min_dist;
}

double closest_pair(std::vector<std::pair<int, int>>& points) {
    if (points.size() <= 3) {
        return closest_pair_helper(points);
    }
    // Divide and conquer logic here (also used in divide_conquer.cpp)
    return 0.0;
}