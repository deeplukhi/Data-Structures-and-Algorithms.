#include <iostream>
#include <stack>

int main() {
    // Creating a stack using STL
    std::stack<int> stk;

    // Push elements into the stack
    stk.push(10);
    stk.push(20);
    stk.push(30);

    // Access the top element
    std::cout << "Top element: " << stk.top() << std::endl;

    // Pop the top element
    stk.pop();
    std::cout << "Top element after pop: " << stk.top() << std::endl;

    // Check if the stack is empty
    if (stk.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    // Stack size
    std::cout << "Stack size: " << stk.size() << std::endl;

    return 0;
}
