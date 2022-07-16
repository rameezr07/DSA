#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<long long int> arr(n), arr2(m);
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	for(int i=0; i<m; i++){
	    cin>>arr2[i];
	}
	sort(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());
	int count = 0, i=0, j=0;
	while(i<n and j<m){
	    if(abs(arr[i] - arr2[j]) <= k){
	        count++;
	        i++;
	        j++;
	    }
	    else if(arr[i] - arr2[j] > k)
	        j++;
	    else
	        i++;
	}
	cout<<count;
	return 0;
}