#include <iostream>

using namespace std;

struct Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node() {
        next = NULL;
        prev = NULL;
    }
};

class Deque {
public:
    Node* head;
    Node* tail;

    Deque() {
        head = NULL;
        tail = NULL;
    }

    void insertFront(int val) {
        Node* newNode = new Node();
        newNode->data=val;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << val << " inserted at front" << endl;
    }

    void insertRear(int val) {
        Node* newNode = new Node();
         newNode->data=val;

        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << val << " inserted at rear" << endl;
    }

    void deleteFront() {
        if (head == NULL) {
            cout << "Deque is empty" << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            else {
                tail = NULL;
            }
            cout << temp->data << " deleted from front" << endl;
            delete temp;
        }
    }

    void deleteRear() {
        if (tail == NULL) {
            cout << "Deque is empty" << endl;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
            else {
                head = NULL;
            }
            cout << temp->data << " deleted from rear" << endl;
            delete temp;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Deque is empty" << endl;
        }
        else {
            Node* curr = head;
            cout << "Deque elements: ";
            while (curr != NULL) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Deque dq;
    int choice, value;
    do {
        cout << "----------Double Ended Queue----------" << endl;
        cout << "1. Insert element at front" << endl;
        cout << "2. Insert element at rear" << endl;
        cout << "3. Delete element from front" << endl;
        cout << "4. Delete element from rear" << endl;
        cout << "5. Display elements" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter the value to be inserted at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout<<"Exiting";
                break;
            default:
                cout<<"VAlid";

        }
    }

    while(choice!=6);
    return 0;
}
