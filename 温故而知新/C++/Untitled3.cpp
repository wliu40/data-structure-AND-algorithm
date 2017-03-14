#include <iostream>
using namespace std;


void fun1(int *arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] += 1;
	}	
}
void show(int *arr, int size){
	cout << endl;
	for(int i =0; i<size; i++){
		cout << *(arr+i) << " "; 
	}	
}

void fun2(int *&arr, int size){
	for(int i =0; i<size; i++){
		arr[i] += 1; 
	}
}

int main(){
	
    const int size = 4;
	int arr[size] = {1,2,3,4};	
	show(arr, size);//1,2,3,4
	
	fun1(arr, size);
	show(arr, size);//2,3,4,5
	
	int *arr2 = new int[size];
	for(int i = 0; i < 4; i++){
		arr2[i] = 6+i;
	}
	
	show(arr2, size);//6,7,8,9
	fun2(arr2, size);
	show(arr2, size);//7,8,9,10
	
	fun1(arr2, size);
	show(arr2, size);//8,9,10,11
	
	int x = 10;
	int *px = &x;
	int &ax = x;//ax is alias of x
	
	*px = 100;
	cout << endl;
	cout << x << endl; //100
	
	ax = 200;
	cout << x << endl;//200
	
	const int &cx = x;//can't change x via cx
	cout << cx << endl; //200
	
} 
