/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
bool checkbst(Node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return true;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return false;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        checkbst(node->left, min, node->data-1) && // Allow only distinct values  
        checkbst(node->right, node->data+1, max); // Allow only distinct values  
}  
	bool checkBST(Node* root) {
        return checkbst(root,INT_MIN,INT_MAX);
        
	}
