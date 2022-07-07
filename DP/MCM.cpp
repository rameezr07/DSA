int solve(vector<int>& values, vector<vector<int>> &t, int i, int j){
    if(t[i][j] != -1)
        return t[i][j];
    int res = 0;
    for(int k=i+1; k<j; k++){
        res = min((res == 0 ? INT_MAX : res), solve(values, t, i, k) + solve(values, t, k, j) + values[i-1] * values[k-1] * values[j-1]);
    }
    return t[i][j] = res;
}