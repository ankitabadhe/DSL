#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    bool isEmpty() {
        return top == NULL;
    }
    void push(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void topElement() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, data;
        cout << "Menu:" << endl;
        cout << "1. Push element onto the stack" << endl;
        cout << "2. Pop element off the stack" << endl;
        cout << "3. Display top element" << endl;
        cout << "4. Display all elements" << endl;
        cout << "5. Quit" << endl;
        do {
        cout << "Enter your choice: ";
        cin >> choice;
        // Perform the selected operation
        switch (choice) {
        case 1:
            cout << "Enter element to push: ";
            cin >> data;
            stack.push(data);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.topElement();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } 
	while (choice != 5);
    return 0;
}

