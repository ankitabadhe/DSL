#include<iostream>
using namespace std;

void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++)
cout << arr[i] << " ";
cout << endl;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

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
int main(){
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
}
