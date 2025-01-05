class Solution {
public:
    long long INF=1e15;
    void floydWarshall(vector<vector<long long>>&dist){
    int i, j, k;
    int V=dist.size();
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])&& (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>v(26,vector<long long>(26,INF));
        int n=original.size();
        for(int i=0;i<n;i++){
                v[original[i]-'a'][changed[i]-'a']=min(v[original[i]-'a'][changed[i]-'a'],1LL*cost[i]);
        }
        floydWarshall(v);
        long long ans=0;
        int m=source.size();
        for(int i=0;i<m;i++){
            if(source[i]==target[i]){
                continue;
            }
            else{
                long long val=v[source[i]-'a'][target[i]-'a'];
                if(val==INF){
                    return -1;
                }
                ans+=val;
            }
        }
        return ans;
    }
};