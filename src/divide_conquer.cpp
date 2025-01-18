#include "divide_conquer.h"
#include "brute_force.h"
#include "strip_closest.h"
#include <algorithm>
#include <limits>

double closest_pair(std::vector<std::pair<int, int>>& points) {
    if (points.size() <= 3) {
        return brute_force(points);
    }

    size_t mid = points.size() / 2;
    auto mid_point = points[mid];

    std::vector<std::pair<int, int>> left(points.begin(), points.begin() + mid);
    std::vector<std::pair<int, int>> right(points.begin() + mid, points.end());

    double dist_left = closest_pair(left);
    double dist_right = closest_pair(right);

    double d = std::min(dist_left, dist_right);

    std::vector<std::pair<int, int>> strip;
    for (const auto& point : points) {
        if (std::abs(point.first - mid_point.first) < d) {
            strip.push_back(point);
        }
    }

    return std::min(d, strip_closest(strip, d));
}
