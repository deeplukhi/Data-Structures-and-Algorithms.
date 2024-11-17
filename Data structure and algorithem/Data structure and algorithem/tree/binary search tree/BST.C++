#include<iostream>
#include<queue>
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

// Function to find the maximum value in the BST
node* maxValue(node* root) {
    node* temp = root;
    while (temp->right != NULL) { 
        temp = temp->right;
    }
    return temp;
}

// Function to find the minimum value in the BST
node* minValue(node* root) {
    node* temp = root;
    while (temp->left != NULL) { 
        temp = temp->left;
    }
    return temp;
}

node* deleteBTSNode(node* root, int val){
    if(root == NULL)
        return NULL;
    
    if(root -> data == val){
        // 0 child
        if(root -> left == NULL && root -> right == NULL ){
            delete root;
            return NULL;
        }
        
        // 1 child
            // left child 
            if(root -> left != NULL && root -> right == NULL ){
                node* temp = root -> left;
                delete root;
                return temp;
            }
            // right child
            if(root -> left == NULL && root -> right != NULL ){
                node* temp = root -> right;
                delete root;
                return temp;
            }


        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minValue(root->right)->data;
            root -> data = mini;
            root -> right = deleteBTSNode(root->right,val);
            return root;
        }
    }
    else if(root -> data > val){
        root -> left = deleteBTSNode(root -> left, val);
        return root;
    }
    else if(root -> data < val){
        root -> right = deleteBTSNode(root -> right, val);
        return root;
    }
}

// Function to find the inorder predecessor
node* findPredecessor(node* root, node* target) {
    node* predecessor = nullptr;

    while (root) {
        if (target->data <= root->data) {
            root = root->left; // Go left
        } else {
            predecessor = root; // Update predecessor
            root = root->right; // Go right
        }
    }
    return predecessor;
}

// Function to find the inorder successor
node* findSuccessor(node* root, node* target) {
    node* successor = nullptr;

    while (root) {
        if (target->data >= root->data) {
            root = root->right; // Go right
        } else {
            successor = root; // Update successor
            root = root->left; // Go left
        }
    }
    return successor;
}

void levelOreded(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node *temp = q.front();

        q.pop();
        if ( temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main(){
        node* root = NULL;
        cout << " Enter data for BST Tree : "<< endl;
        takeInput(root);

        cout << " Level order tarversal : "<< endl;
        levelOreded(root);

        cout << " max : "<< maxValue(root)->data;

        cout<< " min : " << minValue(root)->data;

        deleteBTSNode(root,60);

        cout << " Level order tarversal : "<< endl;
        levelOreded(root);

        cout << " max : "<< maxValue(root)->data;

        cout<< " min : " << minValue(root)->data;
    return 0;
}