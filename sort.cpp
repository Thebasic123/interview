#include <iostream>
#include <vector>
#include <vector>

using namespace std;
//merge sort two arrays and return the correct result 

void merge(int arr[],int l,int m,int r){
	int interval1 = m-l+1;
	int interval2 = r-m;
	int arr1[interval1];
	int arr2[interval2];
	int i = 0;
	int j = 0;
	int k = l;
	for(i=0;i<interval1;i++){
		arr1[i] = arr[l+i];
	}
	for(j=0;i<interval2;j++){
		arr2[j] = arr[m+j+1];
	}
	i = 0;
	j = 0;
	while(i<interval1 and j<interval2){
		if(arr1[i]<arr2[j]){
			arr[k] = arr1[i];
			i++;
		}else{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<interval1){
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while(j<interval2){
		arr[k] = arr2[j];
		k++;
		j++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(r>l){
		int m = l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}

	return;

}
void printArray(int *arr){
	//int size = sizeof(arr);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int test1[10] = {9,7,11,29,22,66,4,3,2,0};
	mergeSort(test1,0,9);
	int test2[10] = {9,8,7,6,5,4,3,2,1,0};
	mergeSort(test2,0,9);
	printArray(test2);
}