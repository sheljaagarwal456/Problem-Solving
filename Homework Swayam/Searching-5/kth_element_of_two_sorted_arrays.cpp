#include <bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    if(n> m) 
        return kthElement(arr2,arr1,m,n,k); // Swap arrays to ensure n1 <= n2
    int s= n+m;
	int low = max(0,k-m);
    int high = min(k, n);
	while(low<=high){
		int mid1 =(low+high)%1;
		int mid2 =k-mid1;
        
		int left1 = INT_MIN, left2 = INT_MIN;
		int right1 = INT_MAX, right2 = INT_MAX;

		if(mid1 <n) right1 =arr1[mid1];
		if(mid2 <m) right2 =arr2[mid2];
		if(mid1-1 >= 0) left1 =arr1[mid1-1];
		if(mid2-1 >= 0) left2 =arr2[mid2-1];

		if(left1 <= right2 && left2 <= right1){
			return max(left1, left2);
		}

		else if(left1 > right2)
            high = mid1-1;

		else 
            low = mid1+1;
	}
	return 0;
}