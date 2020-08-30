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

/* using vcotrs not my solution bbut seemed simpler than mine*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> leftNode, rightNode;
int swapLevel;

void traverse(int node=1){
    if (node == -1) return;
    traverse(leftNode[node]);
    cout << node << " ";
    traverse(rightNode[node]);
    if (node == 1) cout << endl;
}

void swap(int level=1, int node=1) {
	if (node == -1) return;
	if (level % swapLevel == 0) {
		int tmp = leftNode[node];
		leftNode[node] = rightNode[node];
		rightNode[node] = tmp;
	}
	swap(level+1, leftNode[node]);
	swap(level+1, rightNode[node]);
}

int main() {
    int count;    
    cin>>count;
	leftNode.push_back(0);
    rightNode.push_back(0);
    while(count--){
        int L, R;
        cin>>L>>R;
        leftNode.push_back(L);
        rightNode.push_back(R);
    }
    cin>>count;
    while(count--){
		cin >> swapLevel;
		swap();
		traverse();
	}
    return 0;
}
