struct Node{
    Node*links[2];
    int x=0;
};
class Trie{
    public:
    Node*root;
    Trie(){
        root=new Node();
    }
    void insert(int n){
        Node* temp=root;
        for(int i=31; i>=0; i--){
            int b=(n>>i) &1;
            if(temp->links[b]==NULL){
                Node* newnode=new Node();
                temp->links[b]=newnode;
            }
            temp=temp->links[b];
            temp->x++;
        }
    }
    int count_of_pairs(Node* node, int indx,int num, int maxi){
        if(node==NULL){
            return 0;
        }
        if(indx<0){
            return node->x;
        }
        int result=0;
        int numb=(num>>indx)&1;
        int maxib=(maxi>>indx)&1;
        if(numb==1){
           if(maxib==1){
               if(node->links[1]!=NULL){
             result+=node->links[1]->x;
               }
             result+=count_of_pairs(node->links[0],indx-1,num,maxi);
           }
           else{
             result+=count_of_pairs(node->links[1],indx-1,num,maxi);
           }
        }
        else{
          if(maxib==1){
              if(node->links[0]!=NULL){
             result+=node->links[0]->x;
              }
         result+=count_of_pairs(node->links[1],indx-1,num,maxi);
          }
          else{
             result+=count_of_pairs(node->links[0],indx-1,num,maxi);
          }
        }
        return result;
    }
};


class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie T;
        int result=0;
        for(auto it:nums){
            int right=T.count_of_pairs(T.root,31,it,high);
            int left=T.count_of_pairs(T.root,31,it,low-1);
         result+=(right-left);
            cout<<right<<" "<<left<<endl;
            T.insert(it);
        }  
        return result;
    }
};