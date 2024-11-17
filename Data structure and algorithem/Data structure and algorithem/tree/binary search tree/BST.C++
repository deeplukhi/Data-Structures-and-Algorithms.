#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        } 
};

node* insertIntoBTS(node* root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if( d < root -> data){
        root -> left = insertIntoBTS(root->left,d);
    }
    else{
        root -> right = insertIntoBTS(root->right,d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBTS(root,data);
        cin>>data;
    }
}

int main(){
        node* root = NULL;
        cout << " Enter data for BST Tree : "<< endl;
        takeInput(root);
    return 0;
}