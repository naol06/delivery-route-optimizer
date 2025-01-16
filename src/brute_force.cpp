#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double brute_force(const std::vector<std::pair<int, int>>& points) {
    int n = points.size();
    double min_dist = std::numeric_limits<double>::max();
    
    // Generate all permutations of the points and calculate total distance
    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;
    
    do {
        double total_dist = 0;
        for (int i = 0; i < n - 1; ++i) {
            total_dist += distance(points[indices[i]].first, points[indices[i]].second, points[indices[i + 1]].first, points[indices[i + 1]].second);
        }
        total_dist += distance(points[indices[n - 1]].first, points[indices[n - 1]].second, points[indices[0]].first, points[indices[0]].second);
        min_dist = std::min(min_dist, total_dist);
    } while (std::next_permutation(indices.begin(), indices.end()));

    return min_dist;
}

int main() {
    std::vector<std::pair<int, int>> points = {{0, 0}, {1, 2}, {3, 1}, {5, 4}};
    std::cout << "Brute Force Minimum Distance: " << brute_force(points) << std::endl;
    return 0;
}
