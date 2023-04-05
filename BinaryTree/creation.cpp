#include<bits/stdc++.h>
using namespace std;

/* using struct to make user defined data type */
/*
struct Node{
    int data;
    Node *left;
    // for the left pointer ( for the left child )
    Node *right;
    // the right pointer for the right child
}
*/ 

/*
// Method 2: Using "class" to make
// user-define data type
class Node
{
  public:
    int data;
    Node* left;
    Node* right;
};
*/

class node{
    public : 
    int data;
    node *left;
    node *right;


    node(int val ){
        data = val;

        // setting the left and the right child pointers as null 
        // int he constructor 
        left =  NULL;
        right = NULL;
    }

    void display(node *root){
        cout<<root->data<<"\n";
        if(root->left!=NULL){
            return root->display(root->left);
        }if(root->right!= NULL){
            return root->display(root->right);
        }
    }
};



int main(){

    node *root = new node(12);
    // creating a root node 
    // and passing the value of 12 inside it 
    // the constructor will handle that

    root->left = new node(11);
    // creating a new node to the left of the root node 
// with vlaue of 11

    root->right = new node(10);
    // creating a new node to the right of the root node 
    // with the value of 10

    root->display(root);



    return 0;
}