//selection sort
#include<iostream>
using namespace std;
 void selectionsort( int arr[] , int n){
 	int i , j , k;
 	for(i=0;i<n-1;i++){
 		k=i;
 		for(j=i+1;j<n;j++){
 			if(arr[j]<arr[k]){
 				k=j;
			 }
		 }
		 int temp=arr[i];
		 arr[i]=arr[k];
		 arr[k]=temp;
	 }
 }
 int main(){
 	int arr[100] , z,i,j;
 	printf("Enter the number of elements you want to insert in the array : ");
 	scanf("%d",&z);
 	for(i=0;i<z;i++){
 		printf("Enter the value of element %d : ",i+1);
 		scanf("%d",&arr[i]);
	 }
	selectionsort(arr , z);
	printf("SORTED ARRAY: \n");
	for(i=0;i<z;i++){
 		printf("%d\t",arr[i]);
	 }
	 return 0;
 }