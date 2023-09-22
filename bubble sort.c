//bubble sort
#include<stdio.h>
void bubblesort(int a[] , int n);
int main(){
	int a[100],n,i,j;
	printf("Enter the number of elements you want in array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the element: ");
		scanf("%d",&a[i]);
	}
	printf("ARRAY BEFORE SORTING : ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	bubblesort(a,n);
	printf("\nARRAY AFTER SORTING : ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

//void bubblesort(int a[] , int n){
//	int i,temp,j;
//	for(i=0;i<n;i++){
//		for(j=i+1;j<n;j++){
//		if(a[j]<a[i]){
//		    temp = a[i];
//			a[i] = a[j];
//			a[j]=temp;
//		}
//	}
//	}
//}

//void bubblesort(int a[] , int n){
//	int i,temp,j;
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//		if(a[j]<a[i]){
//		    temp = a[i];
//			a[i] = a[j];
//			a[j]=temp;
//		}
//	}
//	}
//}

void bubblesort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
}
}
}