 #include<iostream>
using namespace std;

void printArray(int arr[], int size) {
        int i;
        for (i = 0; i < size; i++)
                cout << arr[i] << " ";
        cout << endl;
}
void bubble_sort(int A[], int n) {
        int temp;
        for (int k = 0; k < n - 1; k++) {
                // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations
                for (int i = 0; i < n - k - 1; i++) {
                        if (A[i] > A[i + 1]) {
                                // here swapping of positions is being done.
                                temp = A[i];
                                A[i] = A[i + 1];
                                A[i + 1] = temp;
                        }

                }
                cout << "Pass" << k << " : ";
                printArray(A, n);
        }
}

int main() {
        int n, i, j, search, first, last, middle, temp;
        cout << "Enter total number of elements :";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
                cout << "Enter element " << i + 1 << " : ";
                cin >> arr[i];
        }

        bubble_sort(arr, n);
        cout << "Sorted array : ";
        printArray(arr, n);
        cout << "\nEnter a number to find :";
        cin >> search;
        first = 0;
        last = n - 1;
        middle = (first + last) / 2;
        while (first <= last) {
                if (arr[middle] < search) {
                        first = middle + 1;

                } else if (arr[middle] == search) {
                        cout << search << " found at location " << middle + 1 << "\n";
                        break;
                } else {
                        last = middle - 1;
                }
                middle = (first + last) / 2;
        }
        if (first > last) {
                cout << "Not found! " << search << " is not present in the list.";
        }
}

