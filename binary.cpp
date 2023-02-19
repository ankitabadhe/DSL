#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice, index;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    do {
        cout << "\nBinary Search Operations:" << endl;
        cout << "1. Search" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the key to search: ";
            cin >> key;
            index = binarySearch(arr, n, key);
            if (index == -1) {
                cout << key << " is not found in the array." << endl;
            }
            else {
                cout << key << " is found at index " << index << " in the array." << endl;
            }
            break;
        case 2:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 2);

    return 0;
}
