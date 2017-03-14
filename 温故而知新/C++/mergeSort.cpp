#include <iostream>
using namespace std;

void mergeSortRec(int *arr, int lo, int hi, int *aux){
	if(lo>=hi) return;
	int mid = lo + (hi-lo)/2;
	mergeSortRec(arr, lo, mid, aux);
	mergeSortRec(arr, mid+1, hi, aux);
	
	for(int i = lo; i <= hi;i++){
		aux[i] = arr[i];
	}
	int i = lo;
	int j = mid+1;
	int k = lo;
	while(i <= mid && j <= hi){
		if (aux[i] < aux[j]){
			arr[k++] = aux[i++];
		}
		else
			arr[k++] = aux[j++];
	}
	while(i <= mid){
		arr[k++] = aux[i++];
	}
	while(j <= hi){
		arr[k++] = aux[j++];
	}	
}
void mergeSort(int *arr, int size){
	int *aux = new int[size];
	mergeSortRec(arr, 0, size, aux);
}


void foo(int *arr){
	cout << sizeof(arr)/sizeof(int) << endl;
}
void show(int *arr, int size){
	for(int i =0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{	
	int arr[] = {1,2,-3,6,0,9};
	//cout << sizeof(arr)/sizeof(int) << endl;
	show(arr, 6);
	//int *arr1 = new int[5];
	
	mergeSort(arr, 6);
	show(arr, 6);
	
	
}

