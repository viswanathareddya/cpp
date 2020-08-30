#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

void inorder_traverse(Node* root){
        if(root==NULL){
            return;
        }
        inorder_traverse(root->left);
        cout << root->data << " ";
        inorder_traverse(root->right);
}

void swap_nodes(Node* root,int level, int k){
        if (root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL ){
            return;
        }
        if(level%k==0 ){
            Node* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        swap_nodes(root->left,level+1,k);
        swap_nodes(root->right,level+1,k);
        
}
int main() {
    int count;    
    cin>>count;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    queue<Node*> tempq;
    Node* ln;
    Node* rn;
    Node* temp;
    Node* root= new Node(1);
    tempq.push(root);
    while(count--){
        int L, R;
        cin>>L>>R;
        if (L==-1){
            ln=NULL;
        }
        else{
            ln=new Node(L);
        }
        if (R==-1){
            rn=NULL;
        }
        else {
            rn=new Node(R);
        }
        temp=tempq.front();
        temp->left=ln;
        temp->right=rn;
        tempq.pop();
        if(temp->left!=NULL){
        tempq.push(temp->left);
        }
        if (temp->right!=NULL){
        tempq.push(temp->right);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        swap_nodes(root,1,k);
        inorder_traverse(root);
        cout<<endl;
    }
  
    return 0;
}
