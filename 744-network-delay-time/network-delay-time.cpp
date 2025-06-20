#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> adj;
        for (const auto& time_edge : times) {
            int u = time_edge[0];
            int v = time_edge[1];
            int w = time_edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, numeric_limits<int>::max());

        priority_queue<pair<int, int>,
                            vector<pair<int, int>>,
                            greater<pair<int, int>>> minHeap;

        dist[k] = 0;
        minHeap.push({0, k});

        int max_time = 0;

        while (!minHeap.empty()) {
            int current_time = minHeap.top().first;
            int u = minHeap.top().second;
            minHeap.pop();

            if (current_time > dist[u]) {
                continue;
            }

            if (adj.count(u)) {
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int travel_time = edge.second;

                    if (dist[u] + travel_time < dist[v]) {
                        dist[v] = dist[u] + travel_time;
                        minHeap.push({dist[v], v});
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dist[i] == numeric_limits<int>::max()) {
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};