#include <iostream>
using namespace std;
class stack{
public:
    int size;
    int *arr;
    int top;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if (size - top > 1){
            arr[top++];
            arr[top] = element;
        }
        else{
            cout << "stack is overflow" << endl;
        }
    }
    void pop(){
        if (top >= 0){
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    }
    int peek(){
        if (top >= 0){
            return arr[top];
        }
        else{
            cout << "stack is empty" << endl;
        }
    }
    bool isEmpty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    stack s(5);

    s.push(6);
    s.push(0);
    s.push(8);
    s.push(4);

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;
    if (s.isEmpty()){
        cout << "ok" << endl;
    }
    else{
        cout << "not ok " << endl;
    }

    return 0;
}