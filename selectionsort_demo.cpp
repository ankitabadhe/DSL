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



void selectionSort(int A[],int n){
 
 for (int k=0;k<n-1;k++)
 {
 	int min = k;
 	for(int j=k+1;j<n;j++){
 		
 		if(A[j]<A[min])
 			min=j;
 				 
	 }
	 
	 	int temp = A[k];
	 	A[k]=A[min];
	 	A[min]=temp;
	
	 cout << "Pass " << k+1 << ":";
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
	

	selectionSort(a,n);
	cout << "Sorted Array :" ;
	printArray(a,n);
	
}
