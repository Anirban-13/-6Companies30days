class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0]; 
        });
        int n=envelopes.size();
        vector<int>v4;
        v4.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            auto it=lower_bound(v4.begin(),v4.end(),envelopes[i][1]);
            if(it==v4.end()){v4.push_back(envelopes[i][1]);}
            else{
                *it=envelopes[i][1];
            }
        }
        return v4.size();
    }
};