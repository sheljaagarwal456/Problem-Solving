class Solution {
public:

    int binary(int n ){
    
        int s=0;
        int e=n;
        long long  int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            long long int square=mid*mid;
            if(square==n){
                return mid;
            }
            if(square<n){
                //can be a potential answer
                ans=mid;
                //search better answer
                s=mid+1;
            }
            //else right part se left me aao kyunki right me answer nhi hai
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
        
    }
    int mySqrt(int x) {
        return binary(x);
    }

};