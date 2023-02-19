#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
	
	for(int i=0;i<size;i++)
	{

	cout << arr[i] << " ";
	cout << endl;
    }
}



void insertionSort(int A[],int n){
 
 for (int k=1;k<n;k++)
 {
 	int temp = A[k];
     int j=k-1;
  while(j>=0 && A[j]>temp){
  	
  	A[j+1]=A[j];
  	j--;
  }
	A[j+1]=temp;
	 cout << "Pass " << k << ":";
	 printArray(A,n);
	  }
	
}


int main(){
    int n;
	cout << "Enter the number of elements you want to sort :" ;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		
		cout << "Enter element " << i+1 << ":";
		cin >> a[i];
	}
	

	insertionSort(a,n);
	cout << "Sorted Array :" ;
	printArray(a,n);
	
}
