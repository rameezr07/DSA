class Solution{
		

	public:
	int LCS(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.length(), n = str2.length();
        int t[m+1][n+1];
        for(int i=0; i<=m; i++){
            t[i][0] = 0;
        }
        for(int i=0; i<=n; i++){
            t[0][i] = 0;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
	} 
};