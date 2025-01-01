class Solution {
public:
    
    int dijkstra(int V, vector<vector<int>> adj[], int S,int distanceThreshold)
    {
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>st;
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            int distance=it.first;
            int node=it.second;
            st.erase(it);
            for(auto i:adj[node]){
                int adjdist=i[1];
                int adjnode=i[0];
                if(distance+adjdist<dist[adjnode]){
                    st.erase({dist[adjnode],adjnode});
                    dist[adjnode]=distance+adjdist;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(dist[i]<=distanceThreshold)cnt++;
        }
        return cnt;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<int>>adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++){
            vector<int>dum={edges[i][1],edges[i][2]};
            adj[edges[i][0]].push_back(dum);
            dum[0]=edges[i][0];
            adj[edges[i][1]].push_back(dum);
        }
        int ans=2e9;
        int val;
       for(int i=0;i<n;i++){
        if(dijkstra(n,adj,i,distanceThreshold)<=ans){
            ans=min(dijkstra(n,adj,i,distanceThreshold),ans);
            val=i;
        }
       } 
       return val;
    }
};