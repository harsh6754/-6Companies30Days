#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with infinity
        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
        
        // Distance to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Populate the distance matrix with the given edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max()) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Find the city with the smallest number of reachable cities
        // and if there is a tie, choose the city with the greatest number.
        int minReachableCities = numeric_limits<int>::max();
        int bestCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};

int main() {
    int n, m, distanceThreshold;
    
    // Input: number of cities (n) and number of edges (m)
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter the distance threshold: ";
    cin >> distanceThreshold;
    
    // Input: edges
    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    // Solve the problem
    Solution sol;
    int result = sol.findTheCity(n, edges, distanceThreshold);
    
    // Output the result
    cout << "The city with the smallest number of reachable cities is: " << result << endl;
    
    return 0;
}
