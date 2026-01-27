class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for(const auto& x: edges){
            int u = x[0];
            int v = x[1];
            int cost = x[2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,2*cost});

        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // data type which is a pair<int,int> and then vector<pair<int,int>> is a container and greater<pair<int,int>> is a comparator by which i mean to compare the pair and this means it store a min heap 
        vector<int> dist(n,INT_MAX); // define everyone distance as maximum possible 
        dist[0] =0;
        pq.push({0,0});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d>dist[u]) continue;

            if(u == n-1) return d;

            for (auto& edge : adj[u]){
                int v= edge.first;
                int w = edge.second;
                if(dist[u] +w <dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;

    }
};