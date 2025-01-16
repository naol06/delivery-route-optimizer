#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "strip_closest.cpp"

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double closest_pair(std::vector<std::pair<int, int>>& points) {
    if (points.size() <= 3) {
        double min_dist = std::numeric_limits<double>::max();
        for (size_t i = 0; i < points.size() - 1; ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                min_dist = std::min(min_dist, distance(points[i].first, points[i].second, points[j].first, points[j].second));
            }
        }
        return min_dist;
    }

    int mid = points.size() / 2;
    std::vector<std::pair<int, int>> left(points.begin(), points.begin() + mid);
    std::vector<std::pair<int, int>> right(points.begin() + mid, points.end());

    double left_min = closest_pair(left);
    double right_min = closest_pair(right);

    double d = std::min(left_min, right_min);

    std::vector<std::pair<int, int>> strip;
    for (size_t i = 0; i < points.size(); ++i) {
        if (abs(points[i].first - points[mid].first) < d) {
            strip.push_back(points[i]);
        }
    }

    return std::min(d, strip_closest(strip, d));
}

double divide_and_conquer(std::vector<std::pair<int, int>>& points) {
    std::sort(points.begin(), points.end()); // Sort by x-coordinate
    return closest_pair(points);
}

int main() {
    std::vector<std::pair<int, int>> points = {{0, 0}, {1, 2}, {3, 1}, {5, 4}};
    std::cout << "Divide and Conquer Minimum Distance: " << divide_and_conquer(points) << std::endl;
    return 0;
}