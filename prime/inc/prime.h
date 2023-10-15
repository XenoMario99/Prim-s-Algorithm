#pragma once

#include <limits>
#include <vector>

using std::vector;

namespace prime {
std::vector<std::pair<int, int>> minSpanningTree(const vector<vector<int>>& W);
}