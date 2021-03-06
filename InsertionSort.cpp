#include <iostream>
using namespace std;
void Insert(int A[], int r ,int i);
void InsertionSort(int A[], int n);

int main(){
	int numbers;int *A = new int;
	cout<<"Please input the numbers to be sorted: "<<endl;
	cin>>numbers;
	cout<<"Please input numbers separately."<<endl;
	for(int i = 0; i < numbers; i++){
		cin>>A[i];
	}
	InsertionSort(A,numbers);
	cout<<"The sorted array is : ";
	for(int i = 0; i < numbers; i++){
		cout<<A[i]<<"\t";
	}
	return 0;
}
void Insert(int A[], int r ,int i){
	int j = i;
	while(r < A[j]){
		A[j + 1] = A[j];
		j = j - 1;
	}
	A[j + 1] = r;
}
void InsertionSort(int A[], int n){
	int * b = new int[n+1];
	for(int i = 1; i <= n; i++){
		b[i] = A[i-1];
	}
	b[0] = INT_MIN;
	for(int i = 2; i <= n; i++){
		Insert(b, b[i], i - 1);
	}
	for(int i = 0; i < n; i++){
		A[i] = b[i+1];
	}
	delete b;
}


