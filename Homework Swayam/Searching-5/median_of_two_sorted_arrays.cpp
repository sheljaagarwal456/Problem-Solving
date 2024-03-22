// brute force approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>newarr;
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                newarr.push_back(nums1[i]);
                i++;
            }
            else{
                newarr.push_back(nums2[j]);
                j++;
            }

        }
        while(i<n1){
            newarr.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            newarr.push_back(nums2[j]);
            j++;
        }
        //new array bana liya jo n1+n2 size ka hoga
        int n=n1+n2;
        if(n%2 ==1){
            return newarr[n/2];
        }
        return (double)((double) (newarr[n/2])+(double)(newarr[n/2 -1])) /2.0;
    }
};