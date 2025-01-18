#include "brute_force.h"
#include "divide_conquer.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    // Sort points by x-coordinates for divide and conquer
    std::sort(points.begin(), points.end());

    // Brute-force method
    double brute_force_result = brute_force(points);
    std::cout << "Brute Force Minimum Distance: " << brute_force_result << "\n";

    // Divide and conquer method
    double divide_conquer_result = closest_pair(points);
    std::cout << "Divide and Conquer Minimum Distance: " << divide_conquer_result << "\n";

    return 0;
}
