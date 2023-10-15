#pragma once

#include <limits>
#include <vector>

using std::vector;
typedef std::pair<int, int> edge;

namespace prime {
vector<edge> minSpanningTree(const vector<vector<int>>& W);
}