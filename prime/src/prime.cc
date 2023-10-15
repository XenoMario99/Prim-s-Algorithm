#include "prime.h"

vector<edge> prime::minSpanningTree(const vector<vector<int>>& W) {
    vector<edge> F;
    const unsigned long verticesAmount{W.size()};

    vector<int> nearest(verticesAmount - 1, 0);
    vector<int> distance(verticesAmount - 1, 0);

    for (int i{1}; i < verticesAmount; i++) {
        distance[i - 1] = W[0][i];
    }

    for (int i{1}; i < verticesAmount; i++) {
        int min = std::numeric_limits<int>::max();
        int vnear{0};
        for (int j{0}; j < verticesAmount - 1; j++) {
            if (distance[j] != -1) {
                if (distance[j] < min) {
                    min = distance[j];
                    vnear = j + 1;  // distance and nearest vecs are indexed from 0 to verticesAmount - 1, so the real index of nearest verticle is one bigger
                }
            }
        }

        F.push_back(std::pair<int, int>(nearest[vnear - 1], vnear));

        distance[vnear - 1] = -1;

        for (int j{1}; j < verticesAmount; j++) {
            if (W[j][vnear] < distance[j - 1]) {
                distance[j - 1] = W[j][vnear];
                nearest[j - 1] = vnear;
            }
        }
    }

    return F;
}