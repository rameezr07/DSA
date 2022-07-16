#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	long long int res = 0;
	for(int i=1; i<n; i++){
	    int diff = arr[i-1] - arr[i];
	    if(diff > 0){
	        res += diff;
	        arr[i] += diff;
	    }
	}
	cout<<res;
	return 0;
}