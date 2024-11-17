#include <iostream>
using namespace std;

class NStack {
    int *arr, *top, *next;
    int n, size;
    int free;  // Points to the next free slot

public:
    NStack(int N, int S) {
        n = N;       // Number of stacks
        size = S;    // Total size of the array

        arr = new int[size];    // Shared array
        top = new int[n];       // Top of each stack
        next = new int[size];   // Next free or next element in stack

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize all spaces as free
        free = 0;
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1;  // Last element points to -1
    }

    // Push element `x` into `stack_number`-th stack
    bool push(int x, int stack_number) {
        if (free == -1) {
            // No free space left
            cout << "Stack Overflow\n";
            return false;
        }

        // Get the index where we want to insert the element
        int index = free;

        // Update free to point to the next free spot
        free = next[index];

        // Insert the element in the array
        arr[index] = x;

        // Update next to store the old top of the stack
        next[index] = top[stack_number];

        // Update the top to point to the new element
        top[stack_number] = index;

        return true;
    }

    // Pop element from `stack_number`-th stack
    int pop(int stack_number) {
        if (top[stack_number] == -1) {
            // Stack is empty
            cout << "Stack Underflow\n";
            return -1;
        }

        // Get the index of the top element
        int index = top[stack_number];

        // Update the top to point to the next element in the stack
        top[stack_number] = next[index];

        // Add the current index to the free list
        next[index] = free;
        free = index;

        // Return the popped element
        return arr[index];
    }
};

int main() {
    NStack ns(3, 10);  // 3 stacks in an array of size 10

    ns.push(15, 0);  // Push 15 to stack 0
    ns.push(45, 1);  // Push 45 to stack 1

    cout << ns.pop(0) << endl;  // Pop from stack 0
    cout << ns.pop(1) << endl;  // Pop from stack 1

    return 0;
}
