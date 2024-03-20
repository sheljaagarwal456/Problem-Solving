class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //sliding window
        int n=s.size();
        int j=0;
        int diff=0;
        int ans=0;
        for(int i=0;i<n;i++){
            diff=diff+abs(s[i]-t[i]);
            while(diff>maxCost){
                diff=diff-abs(s[j]-t[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        //answer return krdo
        return ans;
    }
};