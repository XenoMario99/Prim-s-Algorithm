#include "prime.h"

#include <gtest/gtest.h>

TEST(PrimsTestSuite, minSpanningTree_ok) {
    const int size{5};

    vector<std::pair<int, int>> expected{edge{0, 1}, edge{0, 2}, edge{2, 4}, edge{2, 3}};

    vector<vector<int>> W{vector<vector<int>>(size, vector<int>(size, 0))};
    W[0][0] = 0;
    W[0][1] = 1;
    W[0][2] = 3;
    W[0][3] = std::numeric_limits<int>::max() - 1;
    W[0][4] = std::numeric_limits<int>::max() - 1;
    W[1][0] = 1;
    W[1][1] = 0;
    W[1][2] = 3;
    W[1][3] = 6;
    W[1][4] = std::numeric_limits<int>::max() - 1;
    W[2][0] = 3;
    W[2][1] = 3;
    W[2][2] = 0;
    W[2][3] = 4;
    W[2][4] = 2;
    W[3][0] = std::numeric_limits<int>::max() - 1;
    W[3][1] = 6;
    W[3][2] = 4;
    W[3][3] = 0;
    W[3][4] = 5;
    W[4][0] = std::numeric_limits<int>::max() - 1;
    W[4][1] = std::numeric_limits<int>::max() - 1;
    W[4][2] = 2;
    W[4][3] = 5;
    W[4][4] = 0;

    const auto result{prime::minSpanningTree(W)};

    EXPECT_EQ(expected, result);
}