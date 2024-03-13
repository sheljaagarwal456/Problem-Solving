int ispossible(vector<int>& boards , int mid){
        int n=boards.size();
        //ek painter to hai hi ek board ke liye
        int painter=1;
        //area of boards per painter
        long long totalarea=0;
        for(int i=0;i<n;i++){
            //if sum is less mtlb abhi vo aur paint kr skta hai
            if(totalarea+boards[i] <= mid){
                totalarea += boards[i];
            }
            //warna doosra painter krega
            else{
                painter++;
                totalarea = boards[i];
            }
        }
        return painter;
    }
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low=*max_element(boards.begin(),boards.end());
    int high=accumulate(boards.begin(),boards.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int painters=ispossible(boards,mid);
        //if painters are more than the given painter
        //then we will go in right part to assign more area to a single painter
        if(painters>k){
            low=mid+1;
        }
        //else go to left part
        else{
            high=mid-1;
        }
    }
    return low;
}