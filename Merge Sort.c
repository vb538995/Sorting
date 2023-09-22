#include<stdio.h>
#include<stdlib.h>
int a[500],b[500];
void Adivide(int m , int n);
void output(int n);
void Amergesort(int m , int mid ,int n);
void Dmergesort(int m , int mid , int n);
int main(){
	int i,z;
	
	printf("Enter the number of elements of the array : ");
	scanf("%d",&z);
	printf("Enter the elements of the array : \n");
	for(i=0;i<z;i++){
		printf("\nElement a[%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	
	Adivide(0,z-1);
	output(z);
//	Ddivide(0,z-1);
//	output(z);
	return 0;
	
	
}

void Adivide(int m , int n){
	if(m<n){
		int mid=m+(n-m)/2;
		Adivide(m,mid);
		Adivide(mid+1,n);
		
		Amergesort(m,mid,n);
	}
	else{
		return;
	}
}

void Amergesort(int m, int mid , int n){
	int i;
	int n1=m;
	int n2=mid+1;
	for(i=m;n1<=mid && n2<=n;i++){
		if(a[n1]<=a[n2]){
			b[i]=a[n1++];
		}
		else{
			b[i]=a[n2++];
		}
	}
	
	while(n1<=mid){
		b[i++]=a[n1++];
	}
	
	while(n2<=n){
		b[i++]=a[n2++];
	}
	
	for(i=m;i<=n;i++){
		a[i]=b[i];
	}
}

void output(int m){
	int i;
	printf("\nSorted Array is : ");
	for(i=0;i<m;i++){
		printf("%d\t",a[i]);
	}
}

void Ddivide(int m , int n){
	if(m<n){
		int mid=m+(n-m)/2;
		Ddivide(m,mid);
		Ddivide(mid+1,n);
		
		Dmergesort(m,mid,n);
	}
	else{
		return;
	}
}
void Dmergesort(int m, int mid , int n){
	int i;
	int n1=m;
	int n2=mid+1;
	for(i=m;n1<=mid && n2<=n;i++){
		if(a[n1]>=a[n2]){
			b[i]=a[n1++];
		}
		else{
			b[i]=a[n2++];
		}
	}
	
	while(n1<=mid){
		b[i++]=a[n1++];
	}
	
	while(n2<=n){
		b[i++]=a[n2++];
	}
	
	for(i=m;i<=n;i++){
		a[i]=b[i];
	}
}