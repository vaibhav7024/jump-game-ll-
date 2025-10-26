

class Solution {
public:
    // int solve (vector<int>& nums,vector<int> & dp,int index){
    //     if(index>=nums.size()-1) return 0;
    //     if(dp[index]!=-1) return dp[index];

    //     int ans= nums.size();
    //     for(int i=1;i<=nums[index];i++){
    //         ans = min(ans,1+solve(nums,dp,index+i));
    //     }
    //     return dp[index]= ans;
    // }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,n);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int jump=nums[i];
            for(int j=1;j<=jump && i+j<n;j++){
                dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
        
        return dp[0];
    }
};
