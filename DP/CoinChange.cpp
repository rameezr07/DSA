// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


// Example 1:

// Input:
// n = 4 , m = 3
// S[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.


class Solution {
  public:
    long long int count(int coins[], int m, int amount) {

        // code here.
        long long int t[m+1][amount+1];
        for(int i=1; i<=amount; i++)
            t[0][i] = 0;
        for(int i=0; i<=m; i++)
            t[i][0] = 1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1] <= j){
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[m][amount];
    }
};