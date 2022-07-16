#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    if(i-1==0){cout<<0<<"\n";continue;}
	    unsigned long long j=i*i;
	    unsigned long long c=(j*(j-1))/2;
	    if(i-2==0){cout<<c<<"\n";continue;}
	    unsigned long long num=(i-1)*(i-2)*4;
	    c=c-num;
	    cout<<c<<"\n";
	}
	return 0;
}