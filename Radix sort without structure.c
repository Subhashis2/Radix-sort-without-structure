//....-Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
int Max(int*,int); 
int Digits(int);    
int do_ridix_sort(int*,int*,int);  
int main()
{
	int i,max,digits,*arr,size;
	printf("\n\t\t\t\t\t- : RADIX SORT : -");
	printf("\n\n\n Enter the number of elements in array : "); 
	scanf("%d",&size);
	arr = (int*)malloc(size*sizeof(int));  
	printf("\n Enter the elements : ");  
	for(i=0; i<size; i++)
	scanf("%d",arr+i);
	max = Max(arr,size);             
	digits = Digits(max);       
	for(i=1; i<=digits; i++)
	do_ridix_sort(arr,&i,size);    
	printf("\n\n After sorting the elements are : ");
	for(i=0; i<size; i++)
	printf("%d\t",*(arr+i));
return 0;
}

int Max(int *arr,int size)  
{
	int i,m;
	m = arr[0];
	for(i=1;i<size;i++)
		if(*(arr+i) > m)
			m = *(arr+i);
return m;                             
}

int Digits(int val)        
{
	int digits = 0, rem;
	while(val > 0)
	{
		rem = val % 10;
		val = val - rem;
		val = val / 10;
		digits++;
	}
return digits;            
}

int do_ridix_sort(int *arr, int *loop, int size) 
{                                                   
	int i,j,rem,temp;                  
	int **temp_arr;     
	int check[10];
	temp_arr = (int**)malloc(10*sizeof(int*));
	for(i=0;i<10;i++)
	check[i]=0;             	                   
	for(i=0; i<size; i++)   
	{                                                      
		temp = *(arr+i);  
		for(j=0; j<*loop; j++)    
		{                   
		rem = temp % 10;                                                          
		temp = temp - rem;        
		temp = temp / 10;              
		}
	if(check[rem] == 0)     
	*(temp_arr+rem) = (int*)calloc(1,1*sizeof(int)); 
	
	else  
	*(temp_arr+rem) = (int*)realloc(*(temp_arr+rem),(check[rem]+1)*sizeof(int));
	*(*(temp_arr+rem)+check[rem]) = *(arr+i);
	check[rem]++;   
	}                                                          
int k=0;
for(i=0;i<10;i++)
{
	if(check[i] > 0)
	for(j=0;j<check[i];j++)
	{
		*(arr+k) = *(*(temp_arr+i)+j);
		k++;
	}
}
free(temp_arr);
return 0;
}









