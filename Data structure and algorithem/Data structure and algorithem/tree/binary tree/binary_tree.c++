#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter you data : " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of root : " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of root : " << endl;
    root->right = buildTree(root->right);
    return root;
}

node* buildFromLevelOrdered(node* root){
    queue<node*> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << " Enter left data of : " << temp -> data << endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp -> left);
        }
        cout << " Enter right data of : " << temp -> data << endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp -> right);
        } 
    }
    return root;
    
}

void preordered(node* root){
    if(!root) return;
    cout << root -> data << " ";
    preordered(root -> left);
    preordered(root -> right);
}

void postordered(node* root){
    if(!root) return;
    postordered(root -> left);
    postordered(root -> right);
    cout << root -> data << " ";
}

void inordered(node* root){
    if(!root) return;
    inordered(root -> left);
    cout << root -> data << " ";
    inordered(root -> right);
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

int main()
{
    node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
    root = buildTree(root);
    levelOreded(root);

    buildFromLevelOrdered(root);
    levelOreded(root);

    cout<< " pre";
    preordered(root);

    cout << "post";
    postordered(root);

    cout<< "in ";
    inordered(root);
    return 0;
}