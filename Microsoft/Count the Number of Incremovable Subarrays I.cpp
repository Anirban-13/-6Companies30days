class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool ok = 1; 
                int lst = -1;  
                for (int k = 0; k < n; k++) {
                    if (k >= i && k <= j) {
                        continue;
                    } 
                    else {
                        ok &= (lst < nums[k]);
                        lst = nums[k];     
                        if(ok==0)break;    
                    }
                }
                ans += ok; 
            }
        }
        return ans; 
    }
};