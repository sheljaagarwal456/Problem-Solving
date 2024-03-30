#include<bits/stdc++.h>
using namespace std;
int ret(int n,vector<int>& arr)
{
    //binary search
	int low= 0;
    int high= arr.size() - 1;
    int ans = arr.size();
	while (low<=high)
	{
		int mid= (low+high)/2;
		if (arr[mid]>=n)
		{
			ans=mid; // potential
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return ans;
}
int main()
{
	int n, q;
	cin>>n>>q;
	vector<int>arr(n);
	for(int i=0;i <n;i++)
		cin>>arr[i];
	sort(nums.begin(),nums.end());
	for (int i=0;i<q; i++){
		int t;
		cin >> t;
		cout<<n-ret(t, nums)<<endl;
	}
	return 0;
}