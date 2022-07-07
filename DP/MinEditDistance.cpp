// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

class Solution {
public:
    int minDistance(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int t[m+1][n+1];
        for(int i=0; i<=m; i++){
            t[i][0] = i;
        }
        for(int i=0; i<=n; i++){
            t[0][i] = i;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    t[i][j] = 1 + min(t[i-1][j-1], min(t[i-1][j], t[i][j-1]));
                }
            }
        }
        return t[m][n];
    }
};