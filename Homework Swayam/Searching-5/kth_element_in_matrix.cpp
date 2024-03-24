class Solution {
public:

    int count(vector<vector<int>>&matrix,int val){
        int c=0;
        int n=matrix.size();
        int lb;
        for(int i=0;i<n;++i){
            lb=upper_bound(matrix[i].begin(),matrix[i].end(),val)-matrix[i].begin();
            c+=lb;
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        int mid;
        while(low<high){
            mid=low+(high-low)/2;
            int c=count(matrix,mid);
            if(c<k){
                low=mid+1;
            }
            else{
                high=mid; // yahan mid+1 nhi lena hai
            }
        }
        return low;
    }
};