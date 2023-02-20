#include<iostream>
using namespace std;

void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++)
cout << arr[i] << " ";
cout << endl;
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
int main(){
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
}
