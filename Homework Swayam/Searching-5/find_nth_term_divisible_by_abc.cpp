//Given four integers a, b, c, and N. The task is to find the Nth term which is divisible by either of a, b or c.

include <bits/stdc++.h>
using namespace std;

int count(int mid,int a,int b,int c){
    int x=min({a,b,c});
    int count=0;
    for(int k=x;k<=mid;k++){
        if(k%a==0 || k%b==0 || k%c==0) count++;
    }
    return count;
}
int main()
{
    int a=2,b=3,c=5;
    int n=10;
    //range nikali
    int low=min({a,b,c});
    int high=max({a,b,c})*n;
    //binary search
    while(low<=high)
    {
        int mid=(low+high)/2;
        //agar humara count n ke barabar hai mtlb humein mil gya nth term jo divisible hai
        if(count(mid,a,b,c)==n){
            cout<<mid;
            break;
        }
        //count kam hai mtlb aage jaana hai
        else if(count(mid,a,b,c)<n){
            low=mid+1;
        }
        else high=mid-1;
    }
    return 0;
}