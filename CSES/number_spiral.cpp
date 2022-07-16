#include <iostream>
#include <math.h>
#include<climits>
using namespace std;

void fun(unsigned long long  y, unsigned long long  x){
    unsigned long long i = max(y, x);
    unsigned long long diag = i*i - i + 1;
    if(y == i and x == i){
        cout<<diag<<"\n";
        return;
    }
    bool upper = y < i ? true : false;
    bool even = i % 2  == 0 ? true : false;
    if(upper and even){
        cout<<diag - (i-y)<<"\n";
    }
    else if(upper and !even){
        cout<<diag + (i-y)<<"\n";
    }
    else if(!upper and even){
        cout<<diag + (i-x)<<"\n";
    }
    else if(!upper and !even){
        cout<<diag - (i-x)<<"\n";
    }
    return;
}

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        unsigned long long y, x;
        cin>>y>>x;
        fun(y, x);
    }
    return 0;
}