class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=10)return {};
        vector<string>ans;
        string s1="";
        int n=s.size();
        for(int i=0;i<10;i++){
            s1.push_back(s[i]);
        }
        map<string,int>mp;
        mp[s1]++;
        for(int i=10;i<n;i++){
            s1.erase(s1.begin());
            s1.push_back(s[i]);
            mp[s1]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};