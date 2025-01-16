#include <iostream>
#include <vector>
#include "brute_force.cpp"
#include "strip_closest.cpp"
#include "divide_conquer.cpp"
#include "closest_pair.cpp"

int main() {
    std::vector<std::pair<int, int>> points = {{0, 0}, {1, 2}, {3, 1}, {5, 4}};
    
    std::cout << "Brute Force Minimum Distance: " << brute_force(points) << std::endl;
    std::cout << "Divide and Conquer Minimum Distance: " << divide_and_conquer(points) << std::endl;

    return 0;
}
