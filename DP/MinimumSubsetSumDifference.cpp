// Given an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11   

class Solution{
    vector<int> subsetSum(int sum, int nums[], int n){
        bool t[n+1][sum+1];
        for(int i=1; i<=sum; i++)
            t[0][i] = false;
        for(int i=0; i<=n; i++)
            t[i][0] = true;
        for(int i=1; i<=n; i++){
            for (int j=1; j<=sum; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j] or t[i-1][j-nums[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        vector<int> v;
        for(int i=0; i<=sum; i++){
            if(t[n][i])
                v.push_back(i);
        }
        return v;
    }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sumarr = 0;
        for(int i=0; i<n; i++)
            sumarr += arr[i];
	    vector<int> v = subsetSum(sumarr/2, arr, n);
	    int mn = INT_MAX;
	    for(int i=0; i<v.size(); i++){
	        mn = min(mn, sumarr - 2*v[i]);
	    }
	    return mn;
	} 
};