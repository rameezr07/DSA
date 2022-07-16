#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n==1){
	    cout<<1;
	    return 0;
	}
	if(n<=3){
	    cout<<"NO SOLUTION";
	    return 0;
	}
	int arr[n];
	int mid = ceil(n/2.0) - 1;
	arr[mid] = n;
	int j = 1;
	for(int i=mid+1; i<n; i++){
	    arr[i] = j; 
	    j += 2;
	}
	j = 2;
	for(int i=mid-1; i>=0; i--){
	    arr[i] = j; 
	    j += 2;
	}
	for(int i=0; i<n; i++)
	    cout<<arr[i]<<" ";
}