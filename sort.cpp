 #include <iostream>

using namespace std;

void printArray(int arr[], int size) {
        int i;
        for (i = 0; i < size; i++)
                cout << arr[i] << " ";
        cout << endl;
}

void swap(int * xp, int * yp) {
        int temp = * xp;
        * xp = * yp;
        * yp = temp;
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
                cout << "Pass " << k << " : ";
                printArray(A, n);
        }
}
void selection_sort(int arr[], int n) {
        int i, j, min_idx;
        // One by one move boundary of unsorted subarray
        for (i = 0; i < n - 1; i++) {
                // Find the minimum element in unsorted array
                min_idx = i;
                for (j = i + 1; j < n; j++) {
                        if (arr[j] < arr[min_idx])
                                min_idx = j;
                }
                // Swap the found minimum element with the first element
                swap(arr[min_idx], arr[i]);
                cout << "Pass " << i << " : ";
                printArray(arr, n);

        }
}
void insertion_sort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;

                while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                }
                arr[j + 1] = key;
                cout << "Pass " << i << " : ";
                printArray(arr, n);
        }
}
int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // pivot
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
                //if current element is smaller than pivot, increment the low element
                //swap elements at i and j
                if (arr[j] <= pivot) {
                        i++; // increment index of smaller element
                        swap( & arr[i], & arr[j]);
                }
        }
        swap( & arr[i + 1], & arr[high]);
        return (i + 1);
}

//quicksort algorithm
void quick_sort(int arr[], int low, int high) {
        if (low < high) {
                //partition the array
                int pivot = partition(arr, low, high);
                //sort the sub arrays independently
                quick_sort(arr, low, pivot - 1);
                quick_sort(arr, pivot + 1, high);
        }
}
int shell_sort(int arr[], int n) {

        for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i += 1) {

                        int temp = arr[i];

                        int j;
                        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                                arr[j] = arr[j - gap];

                        arr[j] = temp;

                }

                cout << "Pass " << " :";
                printArray(arr, n);
                cout << " \n";
        }
        return 0;
}
// Function to get the largest element from an array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int arr[], int n, int place)
{
    const int max = 10;
    int output[n];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];


    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        cout<<"Pass: ";
        printArray(arr, n);
    }
}

// Main function to implement radix sort
void radixsort(int arr[], int n)
{
    // Get maximum element
    int max = getMax(arr, n);
    cout<<"The max element is "<<max<<"\n";

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}
int main() {
        int ch, i = 1;
        do {

                while (i <= 10) {
                        cout << "\n \n ** Sorting Techniques " << i << "**" << endl;

                        cout << "1.Bubble Sort" << endl <<
                                "2.Selection Sort" << endl <<
                                "3.Insertion Sort" << endl <<
                                "4.Quick Sort" << endl <<
                                "5.Shell Sort" << endl <<
                                "6.Radix Sort" << endl <<
                                "7.Exit" << endl <<
                                "Enter your choice: ";
                        cin >> ch;

                        switch (ch) {
                        case 1: {
                                cout << "\n 1.Bubble Sort" << endl;

                                int n;

                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element" << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                bubble_sort(arr, n);
                                cout << "Sorted array : ";
                                printArray(arr, n);
                                break;
                        }

                        case 2: {
                                cout << "\n 2.Selection Sort" << endl;
                                int n;
                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element " << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                selection_sort(arr, n);
                                cout << "Sorted array : ";
                                printArray(arr, n);
                                break;
                        }

                        case 3: {
                                cout << "\n 3.Insertion Sort" << endl;
                                int n;
                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element " << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                insertion_sort(arr, n);
                                cout << "Sorted array : ";
                                printArray(arr, n);
                                break;
                        }

                        case 4: {
                                cout << "\n 4.Quick Sort" << endl;
                                int n;
                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element " << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                quick_sort(arr, 0, n - 1);
                                cout << "Sorted array : ";
                                printArray(arr, n);
                                break;
                        }

                        case 5: {
                                cout << "\n 5.Shell Sort" << endl;
                                int n;
                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element " << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                shell_sort(arr, n);
                                cout << "Sorted array : ";
                                printArray(arr, n);
                                break;
                        }
                        case 6: {
                                cout << "\n 6.Radix Sort" << endl;
                                int n;
                                cout << "Enter number of elements to sort : ";
                                cin >> n;
                                int arr[n];
                                for (int i = 0; i < n; i++) {
                                        cout << "Enter element " << i + 1 << " : ";
                                        cin >> arr[i];
                                }

                                radixsort(arr, n);
                                cout << "Sorted array : ";
                                printArray(arr, n);

                                break;
                        }

                        case 7:
                                cout << "Exit";
                                exit(7);

                        default:
                                cout << "Enter correct choice!!!!";

                        }
                        i++;
                }
        } while (i < 2);
}

