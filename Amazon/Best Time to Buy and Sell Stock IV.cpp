class Solution {
public:

    int dp[1002][102][3];
    int f1(int ind,int cnt,int f,int k,vector<int>&prices){
        
        if(ind==prices.size())return 0;
        if(cnt==k&&f==0)return 0;
        if(dp[ind][cnt][f]!=-1)return dp[ind][cnt][f];
        int take=0,nottake=0;
        if(cnt<=k){
            if(f==0&&cnt<k)
            take=-prices[ind]+f1(ind+1,cnt+1,1,k,prices);
            else if(f==1)
            take=max(take,prices[ind]+f1(ind+1,cnt,0,k,prices));
        }
        nottake=0+f1(ind+1,cnt,f,k,prices);
        return dp[ind][cnt][f]=max(take,nottake);
    }

    int maxProfit(int k, vector<int>& prices) {
         memset(dp,-1,sizeof(dp));
        return f1(0,0,0,k,prices);
    }
};