class Solution {
public:

    //function to check possiblity
    bool possible(vector<int>&bloomDay, int day, int m, int k){
        int count=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                b=b+(count/k);
                count=0;
            }
        }
        b=b+(count/k);
        if(b>=m){
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        //convert krna imp hai jisse out of range na jaaye nultiply krke 
        long long val= m*1LL *k * 1LL;
        //not possible
        if(val>bloomDay.size()){
            return -1;
        }
        int mini=INT_MAX , maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};