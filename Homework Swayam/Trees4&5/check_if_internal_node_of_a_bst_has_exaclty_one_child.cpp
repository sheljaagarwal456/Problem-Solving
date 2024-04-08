bool hasOnlyOneChild(int pre[], int size){
    int next, last;
 
    for (int i=0; i<size-1; i++){
        next = pre[i] - pre[i+1];
        last = pre[i] - pre[size-1];
        if (next*last < 0)
            return false;;
    }
    return true;
}