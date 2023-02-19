#include<iostream>
using namespace std;

void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++)
cout << arr[i] << " ";
cout << endl;
}

void bubbleSort(int A[],int n)
{
	int temp;
	for(int k=0;k < n-1;k++)
	{
		for(int j=0;j<n-k-1;j++)
		{
		if(A[j]> A[j+1])
		{	
		temp = A[j];
		A[j] = A[j+1];
		A[j+1] = temp;	
		}
			
		cout << "Pass"  << k+1 << ":";
		printArray(A,n);
	}
}
int main(){
	int n,a[n];
	cout << "Enter the no. elements of array to sort :" ;
	cin >> n;
	for(int i=0;i<n;i++)
	{
	 cout << "Enter element "<< i+1 << " :";	
	 cin >> a[i];
	}
	bubbleSort(a,n);
	cout << "Sorted Array :";
	printArray(a,n);
}
