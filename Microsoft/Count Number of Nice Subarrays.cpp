class Solution {
public:
    int f(int goal,vector<int>&nums){
        if(goal<0)return 0;
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        int ans=0;
        while(i<n&&j<n){
            sum+=nums[j];
            while(i<n&&sum>goal){
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int goal) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1)nums[i]=1;
            else nums[i]=0;
        }
        return f(goal,nums)-f(goal-1,nums);
    }
};