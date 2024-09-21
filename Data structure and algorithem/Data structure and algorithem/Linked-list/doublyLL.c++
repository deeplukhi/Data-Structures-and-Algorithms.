#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* pre = NULL;
    node* next = NULL;

    //contructor
    node(int d){ 
    this -> data = d;
    this -> pre = NULL;
    this -> next = NULL;
    }

    //decontructor
    ~node(){
        if (this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free now :) " << endl;
    }

};

void insertAthead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head -> pre = temp;
    head = temp;
}

void insertAtTAil(node* &tail, int d){
    node* temp = new node(d);
    tail -> next = temp;
    temp -> pre = tail;
    tail = temp;
}

void insertAtPosition(node* &head, node* &tail, int position, int d){
    if(position == 1){
        insertAthead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;
    while (cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){
        insertAtTAil(tail, d);
        return;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next -> pre = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> pre = temp;
}

void deletenode(node* &head, int position){
    node* temp = head;
    if (position == 1){
        temp -> next -> pre = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* pre = NULL;
        int cnt = 1;
        while(cnt < position){
            pre = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> pre = NULL;
        pre -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    
}

void print(node* &head){
    node* temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);

    insertAthead(head, 20);
    print(head);
    insertAthead(head, 30);
    print(head);

    insertAtTAil(tail, 40);
    print(head);
    insertAtTAil(tail, 50);
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);
    insertAtPosition(head, tail, 5, 65);
    print(head);

    deletenode(head, 3);
    print(head);

    cout << "head" << head -> data << endl;
    cout << "tail" << tail -> data << endl;
    return 0;
}