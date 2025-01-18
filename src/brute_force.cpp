#include "brute_force.h"
#include "distance.h"
#include <limits>
#include <cmath>

double brute_force(const std::vector<std::pair<int, int>>& points) {
    double min_dist = std::numeric_limits<double>::max();
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            double dist = distance(points[i].first, points[i].second, points[j].first, points[j].second);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}
