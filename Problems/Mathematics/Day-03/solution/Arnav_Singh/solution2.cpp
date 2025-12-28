#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b;
    cin >> a>>b;
        long long cnt=0;
        long long r=100;
        long long m=  max(a,b);
        long long n=min(a,b);
        a=m;
        b=n;
        while(r!=0){
            long long q=a/b;
            r=a-(b*q);
            a=r;
            long long m=max(a,b);
            long long n=min(a,b);
            a=m;
            b=n;
            cnt+=q;
        }
        cout<<cnt;
    return 0;
}
//time complexity O(log(min(a,b)))
//https://codeforces.com/contest/343/submission/355576599