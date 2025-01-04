#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    vector<vector<int>> buildConversionGraph(const vector<char>& original, const vector<char>& changed, const vector<int>& cost) {
        vector<vector<int>> graph(CHAR_COUNT, vector<int>(CHAR_COUNT, INF));
        
        // Set self-loop costs to 0
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }

        // Populate the conversion graph with given transformations,
        for (size_t i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = min(graph[from][to], cost[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(vector<vector<int>>& graph) {
        // Floyd-Warshall algorithm to find the shortest paths
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                for (int j = 0; j < CHAR_COUNT; j++) {
                    if (graph[i][k] < INF && graph[k][j] < INF) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(const string& source, const string& target, const vector<vector<int>>& graph) {
        long long totalCost = 0;

        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if (graph[sourceChar][targetChar] == INF) {
                return -1; // Conversion not possible
            }
            totalCost += graph[sourceChar][targetChar];
        }

        return totalCost;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};

int main() {
    string source, target;
    cout << "Enter the source string: ";
    cin >> source;

    cout << "Enter the target string: ";
    cin >> target;

    if (source.length() != target.length()) {
        cout << "Error: Source and target strings must have the same length." << endl;
        return 0;
    }

    int m;
    cout << "Enter the number of transformations: ";
    cin >> m;

    vector<char> original(m), changed(m);
    vector<int> cost(m);

    cout << "Enter the original characters: ";
    for (int i = 0; i < m; i++) {
        cin >> original[i];
    }

    cout << "Enter the changed characters: ";
    for (int i = 0; i < m; i++) {
        cin >> changed[i];
    }

    cout << "Enter the cost array: ";
    for (int i = 0; i < m; i++) {
        cin >> cost[i];
    }

    Solution solution;
    long long result = solution.minimumCost(source, target, original, changed, cost);

    if (result == -1) {
        cout << "Conversion not possible." << endl;
    } else {
        cout << "Minimum cost: " << result << endl;
    }

    return 0;
}
