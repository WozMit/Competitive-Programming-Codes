#include <iostream>
using namespace std;
const int MAX = 100005;
int B[MAX];

void SelectionSort(int *A, int low, int high){
	for(int i=low; i<high; i++){
		int min = i;
		for(int j=i+1; j<=high; j++)
			if(A[j] < A[min]) min = j;
		if(min != i) swap(A[i], A[min]);
	}
}

void BubbleSort(int *A, int low, int high){
	bool flag = true;
	while(flag){
		flag = false;
		for(int i=low; i<high; i++)
			if(A[i] > A[i+1]){
				swap(A[i], A[i+1]);
				flag = true;
			}
		high--;
	}
}

void InsertionSort(int *A, int low, int high){
	for(int i=low+1; i<=high; i++){
		int val = A[i], k = i-1;
		while(k>=low && val < A[k]){
			A[k+1] = A[k];
			k--;
		}
		A[k+1] = val;
	}
}

void QuickSort(int *A, int low, int high){
	if(low < high){
		int p = high, i = low, j = high-1;
		while(i <= j)
			if(A[i] > A[p] && A[j] < A[p]) swap(A[i++], A[j--]);
			else if(A[i] > A[p]) j--;
			else if(A[j] < A[p]) i++;
			else{
				i++;
				j--;
			}
		swap(A[i], A[p]);
		QuickSort(A, low, i-1);
		QuickSort(A, i+1, high);
	}
}

void MergeSort(int *A, int low, int high){
	if(low < high){
		int mid = (low+high)>>1;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		int i = low, j = mid+1, k = low;
		for(int t=low; t<=high; t++) B[t] = A[t];
		while(i <= mid && j<= high)
			if(B[i] > B[j]) A[k++] = B[j++];
			else A[k++] = B[i++];
		while(i <= mid) A[k++] = B[i++];
	}
}

void Max_Heapify(int *A, int size, int idx){
	if(2*idx <= size){
		int max = 2*idx;
		if(2*idx < size && A[2*idx+1] > A[max]) max = 2*idx+1;
		if(A[max] > A[idx]){
			swap(A[idx], A[max]);
			Max_Heapify(A, size, max);
		}
	}
}

void HeapSort(int *A, int n){
	n--;
	for(int i=n/2; i>0; i--) Max_Heapify(A, n, i);
	for(int i=n; i>1; i--){
		swap(A[1], A[i]);
		Max_Heapify(A, i-1, 1);
	}
	int aux = A[0], i = 1;
	while(i <= n && A[i] < aux) A[i-1] = A[i++];
	A[i-1] = aux;
}

int main() {
	int n, A[MAX];
	while(cin >> n){
		for(int i=0; i<n; i++) cin >> A[i];
		HeapSort(A, n);
		for(int i=0; i<n; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
