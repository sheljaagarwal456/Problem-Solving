class Solution {
public:

    //check if it is possiblw or not
    bool possible(vector<int> v,long long int mid,int op)
    {
        int count=0;
        for(long int i=0;i<v.size();++i)
        {
            count+=(v[i]-1)/mid;
            //if count is greater than operation
            if(count>op)
                return 0;
        }
        
        return 1;
    }
    int minimumSize(vector<int>& v, int op) {   
        //search space
        long long int low=1;
        long long int high=*max_element(v.begin(),v.end());
        long long int ans=0;        
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            if(possible(v,mid,op))
            {
                ans=mid;
                high=mid-1;
            }
            
            else
                low=mid+1;
        }
        
        return ans;
    }
};