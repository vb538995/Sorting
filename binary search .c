// binary search
#include<stdio.h>
int a[100], n, i, key , lb , ub , p , mid;
int binarysearch(int a[], int lb , int ub , int key){
	mid=(lb+ub)/2;
	if(key==a[mid]){
		return mid;
	}
	else if(key > a[mid]){
		lb = mid+1;
		binarysearch(a , lb , ub , key);
	}
	else{
		ub=mid-1;
		binarysearch(a , lb , ub , key);
	}
}

int main(){
	printf("Enter the number of elements you want in the array : ");
	scanf("%d",&n);
	lb=0;ub=n-1;
	printf("PLEASE ENTER A SORTED ARRAY : \n");
	for(i=0;i<n;i++){
		printf("Enter the element: ");
		scanf("%d",&a[i]);
	}
	printf("Enter the element you want to search in the array: ");
	scanf("%d",&key);
	if(key > a[ub] || key < a[lb]){
		printf("\n\nEntered value is not in the array.");
	}
	else{
		p=binarysearch(a , lb , ub , key);
	}
	printf("Entered value is present on %d position of the array.",p+1);
	return 0;
}
