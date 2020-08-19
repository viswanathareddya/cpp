#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
       
    void topView(Node * root) {
         // Base case 
        if (root == NULL) { 
        return; 
        } 
  
        // Take a temporary node 
        Node* temp = NULL; 
  
        // Queue to do BFS 
        queue<pair<Node*, int> > q; 
  
        // map to store node at each vartical distance 
        map<int, int> mp; 
  
        q.push({ root, 0 }); 
  
        // BFS 
        while (!q.empty()) { 
  
            temp = q.front().first; 
            int d = q.front().second; 
            q.pop(); 
  
        // If any node is not at that vertical distance 
        // just insert that node in map and print it 
            if (mp.find(d) == mp.end()) { 
                mp[d] = temp->data; 
            } 
  
        // Continue for left node 
            if (temp->left!=NULL) { 
                q.push({ temp->left, d - 1 }); 
            } 
  
        // Continue for right node 
            if (temp->right!=NULL) { 
                q.push({ temp->right, d + 1 }); 
            } 
        }

        map<int, int>::iterator itr; 
    
        for (itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << itr->second << ' '; 
        } 
     
        
        
        
        
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
