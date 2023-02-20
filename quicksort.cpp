#include<iostream>
using namespace std;

void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++)
cout << arr[i] << " ";
cout << endl;
}

void swap(int * xp, int * yp) {
        int temp = * xp;
        * xp = * yp;
        * yp = temp;
}

int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // pivot
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
                //if current element is smaller than pivot, increment the low element
                //swap elements at i and j
                if (arr[j] <= pivot) {
                        i++; // increment index of smaller element
                        swap( &arr[i], &arr[j]);
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
int main(){
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
}
