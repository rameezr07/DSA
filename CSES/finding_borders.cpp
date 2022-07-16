#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    string s1 = "", s2 = "";
	for(int i=0; i<n-1; i++){
	    s1.push_back(s[i]);
	    string s3 = "";
	    s3.push_back(s[n-i-1]);
	    s2 = s3+s2;
	    if(!s1.compare(s2))
	        cout<<(i+1)<<" ";
	}
	return 0;
}