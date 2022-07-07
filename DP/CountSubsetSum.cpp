int countSubsetSum(int sum, vector<int>& nums){
    int n = nums.size();
    int t[n+1][sum+1];
    for(int i=0; i<=sum; i++)
        t[0][i] = 0;
    t[0][0] = 1;
    for(int i=1; i<=n; i++){
        for (int j=0; j<=sum; j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}