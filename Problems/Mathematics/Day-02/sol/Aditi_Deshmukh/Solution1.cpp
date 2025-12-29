//We have to find how many pairs have the maximum absolute difference 
//only the highest and the lowest number in the array will have max difference
//so we need to find how many times the highest and lwest element appears and calc their permutations
//time and space complexity is O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long int n;
	    	cin>>n;
	    	int a[n];
	    	for(int i=0;i<n;i++){
			cin>>a[i];
	    	}
	    	long long int j=1,k=1,min=a[0],max=a[0];
	    	//j is no of min elements
	    	//k is no of max elements

	    	for(int i=1;i<n;i++){
	        	if(min<a[i]){
	            		j=1;
	            		min=a[i];
	        	}
	        	else if(min==a[i]){
	        		j++;
	        	}
	        
	        if(max>a[i]){
	            	k=1;
	            	max=a[i];
	        }
	        else if(max==a[i]){
	            	k++;
	        }
	    }
	    
		if(min==max)
			//if all elements are same, permutation formula becomes n*(n-1)
		    	cout<<n*(n-1)<<endl;
		else
	    		cout<<j*k*2<<endl;
	}

}
//https://codeforces.com/problemset/submission/1771/355657715
