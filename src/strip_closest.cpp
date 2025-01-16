#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double strip_closest(std::vector<std::pair<int, int>>& strip, double d) {
    double min_dist = d; // d is the minimum distance so far

    std::sort(strip.begin(), strip.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second; // Sort by y-coordinate
    });

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_dist; ++j) {
            min_dist = std::min(min_dist, distance(strip[i].first, strip[i].second, strip[j].first, strip[j].second));
        }
    }

    return min_dist;
}
