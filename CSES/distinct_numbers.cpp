#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin>>n;
	map<int, int> m;
	for(int i=0; i<n; i++){
	    int j;
	    cin>>j;
	    m[j]++;
	}
	cout<<m.size();
	return 0;
}