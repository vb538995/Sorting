#include<stdio.h>
#include<stdlib.h>

struct person{
	int id;
	char *name;
	int age ;
	int hieght;
	int weight;
};


void min_heapify(struct person a[] , int n, int i);
void max_heapify(struct person a[] ,int n , int i);
void min_heapifyage(struct person a[] ,int n , int i);
void create_min_heapage(struct person a[] , int n);
void create_min_heap(struct person a[] , int n);


void swap(struct person *a , struct person *b){
	struct person temp =*a;
	*a=*b;
	*b=temp;
}

void create_min_heap(struct person a[] , int n){
	int i;
	for(i=n/2 - 1 ;i>=0 ; i--){
		min_heapify(a,n,i);
	}
}

void min_heapify(struct person a[] , int n, int i){
	int smallest=i;
	int left=i*2+1;
	int right=i*2+2;
	
	if(left < n && a[smallest].age  > a[left].age ){
		smallest = left;
	}
	
	if(right < n && a[smallest].age > a[right].age ){
		smallest = right ;
	}
	
	if(smallest!=i){
		swap(&a[i],&a[smallest]);
		min_heapify(a,n,smallest);
	}
}

void create_max_heap(struct person a[] , int n){
	int i;
	for(i=n/2-1; i>=0 ; i--){
		max_heapify(a,n,i);
	}
}

void max_heapify(struct person a[] ,int n , int i){
	int largest = i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && a[largest].weight < a[left].weight){
		largest=left;
	}
	if(right<n && a[largest].weight < a[right].weight){
		largest=right;
	}
	if(largest!=i){
		swap(&a[largest],&a[i]);
		max_heapify(a,n,largest);
	}
}



void create_max_heapage(struct person a[] , int n){
	int i;
	for(i=n/2-1; i>=0 ; i--){
		max_heapifyage(a,n,i);
	}
}

void max_heapifyage(struct person a[] ,int n , int i){
	int largest = i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && a[largest].age < a[left].age){
		largest=left;
	}
	if(right<n && a[largest].age < a[right].age){
		largest=right;
	}
	if(largest!=i){
		swap(&a[largest],&a[i]);
		max_heapifyage(a,n,largest);
	}
}



void create_min_heapage(struct person a[] , int n){
	int i;
	for(i=n/2-1; i>=0 ; i--){
		min_heapifyage(a,n,i);
	}
}

void min_heapifyage(struct person a[] ,int n , int i){
	int largest = i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && a[largest].age > a[left].age){
		largest=left;
	}
	if(right<n && a[largest].age > a[right].age){
		largest=right;
	}
	if(largest!=i){
		swap(&a[largest],&a[i]);
		min_heapify(a,n,largest);
	}
}



int main(){
	int n,i,x;
	struct person *student;
	FILE *fi,*fo;
	fi=fopen("READ.txt","w");
	fo=fopen("OUT.txt","w");
	
	do{
	   printf("\n\n------------MAIN MENU------------");
	   printf("\n1.READ DATA");
	   printf("\n2.CREATE MIN HEAP BASED ON AGE");
	   printf("\n3.CREATE MAX HEAP BASED ON WEIGHT");
	   printf("\n4.DISPLAY WEIGHT OF YOUNGEST PERSON");
	   printf("\n5.INSERT NEW STUDENT DETAILS IN MIN HEAP");
	   printf("\n6.DELETE OLDEST PERSON DETAILS");
	   printf("\n7.---------------EXIT-------------------");
	
	printf("\nCHOOSE : ");
	scanf("%d",&x);
	switch(x){
		case 1: {
			printf("Enter the number of students details you want to Enter : ");
	        scanf("%d",&n);
	        student = (struct person*)malloc(n*sizeof(struct person));
	
        	for(i=0;i<n;i++){
	        	printf("Enter the Details of student[%d] : \n",i+1);
	        	student[i].id=i+1;
		        student[i].name = (char*)malloc(50*sizeof(char));
	        	printf("NAME : ");
		        scanf(" %[^\n]s",student[i].name);
		        printf("Age : ");
		        scanf("%d",&student[i].age);
	         	printf("Hieght : ");
		        scanf("%d",&student[i].hieght);
		        printf("Weight : ");
		        scanf("%d",&student[i].weight);
     	    }
     	    
     	    for(i=0;i<n;i++){
     	    	fprintf(fi,"Student Id : %d\n",student[i].id);
     	    	fprintf(fi,"Student Name : %s\n",student[i].name);
     	    	fprintf(fi,"Student Age :%d\n",student[i].age);
     	    	fprintf(fi,"Student Hieght : %d\n",student[i].hieght);
     	    	fprintf(fi,"Student Weight : %d\n",student[i].weight);
     	    	fputs("\n\n\n",fo);
			 }
			 
			 fclose(fi);
			break;
		}
		
		case 2: {
				create_min_heap(student,n);
	            printf("MIN heap after heapify :\t ");
	            for(i=0;i<n;i++){
	        	printf("%d\t",student[i].age);
	        }
	        fputs("MIN HEAP BASED ON AGE : \n",fo);
	        for(i=0;i<n;i++){
     	    	fprintf(fo,"Student Id : %d\n",student[i].id);
     	    	fprintf(fo,"Student Name : %s\n",student[i].name);
     	    	fprintf(fo,"Student Age :%d\n",student[i].age);
     	    	fprintf(fo,"Student Hieght : %d\n",student[i].hieght);
     	    	fprintf(fo,"Student Weight : %d\n",student[i].weight);
     	    	fputs("\n\n\n",fo);
			 }
			break;
		}
		
		case 3: {
				create_max_heap(student,n);
	            printf("MAX heap after heapify :\t ");
	            for(i=0;i<n;i++){
	         	printf("%d\t",student[i].weight);
           	}
           	
           	fputs("MAX HEAP BASED ON WEIGHT : \n",fo);
	        for(i=0;i<n;i++){
     	    	fprintf(fo,"Student Id : %d\n",student[i].id);
     	    	fprintf(fo,"Student Name : %s\n",student[i].name);
     	    	fprintf(fo,"Student Age :%d\n",student[i].age);
     	    	fprintf(fo,"Student Hieght : %d\n",student[i].hieght);
     	    	fprintf(fo,"Student Weight : %d\n",student[i].weight);
     	    	fputs("\n\n\n",fo);
			 }
			break;
		}
		
		case 4: {
				create_min_heapage(student,n);
				fprintf(fo,"\nWeight of youngest person with age is  :%d and  %.2f reaspectively",student[0].age,(float)student[0].weight);
	            printf("\nWeight of youngest person with age is  :%d and  %.2f reaspectively",student[0].age,(float)student[0].weight);
			break;
		}
		
		case 5 : {
				n++;
	            student=(struct person*)realloc(student , n*sizeof(struct person));
	            printf("\nEnter the Details of new student : ");
	            student[n-1].id=n;
                student[n-1].name=(char*)malloc(50*sizeof(char));
	            printf("\nName : ");
	            scanf("%s",&student[n-1].name);
	            printf("Age : ");
	            scanf("%d",&student[n-1].age);
	            printf("Hieght : ");
	            scanf("%d",&student[n-1].hieght);
            	printf("Weight : ");
	            scanf("%d",&student[n-1].weight);
	
	            create_min_heap(student,n);
	            printf("MIN heap after adding new student :\t ");
	            for(i=0;i<n;i++){
		        printf("%d\t",student[i].age);
		    }
		        fputs("MIN HEAP AFTER ADDING NEW STUDENT DETAILS : \n",fo);
	        for(i=0;i<n;i++){
     	    	fprintf(fo,"Student Id : %d\n",student[i].id);
     	    	fprintf(fo,"Student Name : %s\n",student[i].name);
     	    	fprintf(fo,"Student Age :%d\n",student[i].age);
     	    	fprintf(fo,"Student Hieght : %d\n",student[i].hieght);
     	    	fprintf(fo,"Student Weight : %d\n",student[i].weight);
     	    	fputs("\n\n\n",fo);
			 
	        }
			break;
		}
		case 6 : {
			create_max_heapage(student , n);
	        swap(&student[n-1],&student[0]);
	        n--;
	        student=(struct person*)realloc(student,n*sizeof(struct person));
	        create_max_heapage(student,n);
	        printf("student with highest weight is deleted from the heap.");
	        printf("\nNOW OLDEST STUDENT IS OF %d YEARS. ",student[0].age);
	        
	        fputs("MAX AFTER DELETION OF OLDEST PERSON : \n",fo);
	        for(i=0;i<n;i++){
     	    	fprintf(fo,"Student Id : %d\n",student[i].id);
     	    	fprintf(fo,"Student Name : %s\n",student[i].name);
     	    	fprintf(fo,"Student Age :%d\n",student[i].age);
     	    	fprintf(fo,"Student Hieght : %d\n",student[i].hieght);
     	    	fprintf(fo,"Student Weight : %d\n",student[i].weight);
     	    	fputs("\n\n\n",fo);
			 }
			break;
		}
		case 7 : {
			printf("------------------------------------EXIT------------------------------------");
			return 0;
			break;
		}
       default:
            printf("Invalid option. Please enter a valid option.\n");
            break;
	}
	}while(x!=7);
	fclose(fo);
	return 0;
}
