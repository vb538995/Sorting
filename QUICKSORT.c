#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[] ,int m , int n );
int partition(int a[] ,int m , int n);
int main(){
	int z,i,p,q,c;
	printf("enter the number of element in the array : ");
	scanf("%d",&z);
	int a[z];
	printf("Enter the lowest range : ");
	scanf("%d",&p);
	printf("Enter the highest range : ");
	scanf("%d",&q);	
		FILE *fo;
		fo=fopen("quick.txt","w");
		printf("\nMAIN MENU \n1.Ascending \n2.Descending \n3.Random  \n4.Exit\n");
		printf("CHOOSE : ");
		scanf("%d",&c);
		printf("\n\n\n");
		switch(c){
			case 1: {
				for(i=0;i<z;i++){
	         	int rnd = p + (rand() % (q-p));
	         	a[i]=rnd;
	            }
            	printf("Random elements generated between the given range : \n");
	            for(i=0;i<z;i++){
	         	printf("%d\t",a[i]);
	            }
				quicksort(a,0,z-1);
				
				fputs("Ascending Order of the array elements :  ",fo);
				for(i=0;i<z;i++){
		        fprintf(fo,"%d\t",a[i]);
	            }	
		
	            printf("\nSorted array is : ");
	            for(i=0;i<z;i++){
	         	printf("%d\t",a[i]);
	            }
			break;
			}
			case 2:{
				for(i=0;i<z;i++){
	        	int rnd = p + (rand() % (q-p));
	        	a[i]=rnd;
	            }
              	printf("Random elements generated between the given range : \n");
	            for(i=0;i<z;i++){
	         	printf("%d\t",a[i]);
            	}
				quicksort(a,0,z-1);
				
				fputs("Dscending Order of the array elements :  ",fo);
				for(i=z-1;i>=0;i--){
	          	fprintf(fo,"%d\t",a[i]);
              	}	
		
	            printf("\nSorted array is : ");
	            for(i=z-1;i>=0;i--){
	         	printf("%d\t",a[i]);
	            }
			break;
			}
			case 3:{
				for(i=0;i<z;i++){
	        	int rnd = p + (rand() % (q-p));
	        	a[i]=rnd;
            }
	            printf("Random elements generated between the given range : \n");
	            for(i=0;i<z;i++){
				printf("%d\t",a[i]);
	            }
	            fputs("Random Order of the array elements :",fo);
	            for(i=0;i<z;i++){
	           	fprintf(fo,"%d\t",a[i]);
	            }	
			break;
			}
			case 4:{
				printf("-------------------------PROGRAM END-------------------------");
				return 0;
				break;
			}
		
}
fclose(fo);
}
	
	
void quicksort(int a[] ,int m , int n){
	if(m<n){
		int loc=partition(a,m,n);
		quicksort(a,m,loc-1);
		quicksort(a,loc+1,n);
	}
}

int partition(int a[] ,int m , int n){
	
		int pivot=a[n];
		int i=m-1;
		int j;
		for(j=m;j<=n;j++){
			if(a[j]<pivot){
				i++;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		int t = a[n];
		a[n]=a[i+1];
		a[i+1]=t;
		return i+1;		
}