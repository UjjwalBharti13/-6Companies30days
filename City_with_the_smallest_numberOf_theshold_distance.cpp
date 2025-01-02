class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Fill initial distances based on edges
    for (auto& edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }

    // Set the distance from each node to itself to 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Apply Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int cntcity = n;
    int cityno = -1;

    // Find the city with the smallest number of reachable cities within distanceThreshold
    for (int city = 0; city < n; ++city) {
        int count = 0;
        for (int adjcity = 0; adjcity < n; ++adjcity) {
            if (dist[city][adjcity] <= distanceThreshold) {
                ++count;
            }
        }
        if (count <= cntcity) {
            cntcity = count;
            cityno = city;
        }
    }

    return cityno;
    }
};
