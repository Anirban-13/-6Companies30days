class Solution {
public:
    string getHint(string secret, string guess) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        int cnt=0;
        string s="";
        int n=secret.size();
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])cnt++;
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        string s1=to_string(cnt);
        s+=s1;
        s+="A";
        cnt=0;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                cnt+=min(it.second,mp2[it.first]);
            }
        }
        s1=to_string(cnt);
        s+=s1;
        s+="B";
        return s;
    }
};