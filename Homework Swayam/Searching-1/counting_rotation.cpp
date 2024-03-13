//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int count=0;
	    for(int i=0;i<n-1;i++){
	        if(arr[i+1]<arr[i]){
	            count=i+1;
	        }
	    }
	    return count;
	}

};