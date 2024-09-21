#include<iostream>
using namespace std;
class node{
    public:

    int data;
    node* next;

    //constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //deconstructor
    ~node(){
        if (this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free now :) " << endl;
    }
};

void insertNode(node* &tail, int element, int d){
    if(tail == NULL){
        node* newNode = new node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        node* curr = tail;
        while (curr -> data != element){
            curr = curr -> next;
        }

        node* temp = new node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(node* tail, int val){
    if (tail == NULL){
        cout << "already free no node";
        return;
    }
    else{
        node* prev = tail;
        node* curr = prev -> next;
        while(curr -> data != val){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        if (curr == prev){
            tail = NULL;
        }
        
        curr -> next = NULL;
        delete curr; 
        cout << "memory has been delated";
    }
    
}

void print(node* tail){
    node* temp = tail;
    do
    {
        cout << tail -> data << " ";
        tail = tail -> next;

    } while (tail != temp);
    cout << endl;
}

int main(){
    node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 5);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    return 0;
}