#include "strip_closest.h"
#include "distance.h"
#include <algorithm>
#include <limits>

double strip_closest(std::vector<std::pair<int, int>>& strip, double d) {
    double min_dist = d;
    std::sort(strip.begin(), strip.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_dist; ++j) {
            double dist = distance(strip[i].first, strip[i].second, strip[j].first, strip[j].second);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}