//binary search approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        
        // nums1 chota hona chahiye
        if (n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        int n=n1+n2;
        int left=(n1+n2+1)/2; // left k ]a size kitna hoga
        int low=0, high=n1;
        
        while (low<=high) {
            int mid1=(low+high)>>1; // Calculate mid nums1 ka
            int mid2=left-mid1; // Calculate mid nums2 ka
            
            //sabko int min aur int max le liya
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            //l1, l2, r1, and r2 nikalo
            if (mid1<n1)
                r1=nums1[mid1];
            if (mid2<n2)
                r2=nums2[mid2];
            if (mid1-1>=0)
                l1=nums1[mid1 - 1];
            if (mid2-1>= 0)
                l2=nums2[mid2 - 1];
            
            if (l1<=r2&&l2<=r1) {
                //correct partition pe median aayega
                if(n%2==1)
                    return max(l1, l2);
                else
                    return((double)(max(l1, l2)+min(r1,r2)))/2.0; //double use krenge
            }
            else if (l1>r2) {
                // Move towards the left side of nums1
                high=mid1-1;
            }
            else {
                // Move towards the right side of nums1
                low=mid1+1;
            }
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};

**************----------------------*********************

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
