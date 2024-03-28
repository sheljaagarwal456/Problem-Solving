class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       int evenSum=0;
       int oddSum=0;
       //null tree
       if(root==NULL){
           return 0;
       }
       //make a queue for level order traversal
       queue<Node*>q;
       //root daal do usme
       q.push(root);
       int count=1;
       while(!q.empty()){
           int l =q.size();
           while(l--){
               //ek node leli jo q ke front ko point kre
               Node*f=q.front();
               q.pop();
               //jab odd level pe ho
               if(count%2!=0){
                   oddSum=oddSum+f->data;
               }
               //even level pe
               else{
                   evenSum=evenSum+f->data;
               }
               //left part hai tree ka toh wahan jao
               if(f->left){
                   q.push(f->left);
               }
               //right hai toh wahan jao
               if(f->right){
                   q.push(f->right);
               }
           }
           count++;
       }
       int diff=oddSum-evenSum;
       return diff;
    }
};