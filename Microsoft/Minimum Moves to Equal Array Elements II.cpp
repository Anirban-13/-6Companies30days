class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n&1){
            int med=nums[n/2];
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=abs(med-nums[i]);
            }
            return cnt;
        }
        else{
            int med1=nums[n/2];
            int med2=nums[(n-1)/2];
            int cnt1=0,cnt2=0;
            for(int i=0;i<n;i++){
                cnt1+=abs(med1-nums[i]);
                cnt2+=abs(med2-nums[i]);
            }
            return min(cnt1,cnt2);
        }
        return 1;
    }
};