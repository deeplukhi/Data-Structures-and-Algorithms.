#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
// contructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

// destructor
    ~node(){
        if (this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free now :) " << endl;
    }
};

void insertAthead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTAil(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtposition(node *&head, node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }

    int cnt = 1;
    node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    node *nodetoInsert = new node(d);

    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;

    if (temp->next == NULL)
    {
        insertAtTAil(tail, d);
        return;
    }
}

void deletNode(int position, node *&head)
{
    node *temp = head;
    if (position == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* current = head;
        node* pre = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            pre = current;
            current = current -> next;
            cnt++;
        }
        pre -> next = current -> next;
        current -> next = NULL;
        delete current;
        
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    node *head = node1;
    node *tail = node1;
    print(head);
    // insertAthead(head, 12);
    // print(head);
    // insertAthead(head, 13);
    // print(head);
    // insertAthead(head, 14);
    // print(head);
    // insertAthead(head, 15);
    // print(head);

    insertAtTAil(tail, 12);
    print(head);
    insertAtTAil(tail, 13);
    print(head);
    insertAtTAil(tail, 14);
    print(head);
    insertAtTAil(tail, 15);
    print(head);

    insertAtposition(head, tail, 3, 90);
    print(head);

    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    deletNode(3,head);
    print(head);
    return 0;
}