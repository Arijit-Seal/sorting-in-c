#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

void show(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}
/*************************************************************/
void bubblesort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
/**************************************************************/
void insertion(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			j=i+1;
			t=a[i+1];
		}
		while(j>0&&a[j-1]>t)
		{
			a[j]=a[j-1];
			j--;
			a[j]=t;
		}
	}
}
/**************************************************************/
void selection(int a[],int n)
{
	int i,j,max,max_pos;
	i=0;
	while(i<n-1)
	{
		max=a[0];max_pos=0;j=0;
		while(j<=n-i-1)
		{
			if(a[j]>max)
			{
				max=a[j];
				max_pos=j;
			}
			j++;
		}
		a[max_pos]=a[n-i-1];
		a[n-i-1]=max;
		i++;
	}
	
}
/****************************************************************/
int partition(int a[],int low,int high);
void quicksort(int a[],int low,int high)
{
	int j;
	if(low>=high)
	return;
	j=partition(a,low,high);
	quicksort(a,low,(j-1));
	quicksort(a,(j+1),high);
}
int partition(int a[],int low,int high)
{
	int p,i,j,t;
	p=a[low];
	i=low+1;
	j=high;
	while(i<=j)
	{
	  while(a[i]<p)
	  {
	  	i=i+1;
	  }	
	  while(a[j]>p)
	  {
	  	j=j-1;
	  }
	  if(i<j)
	  {
	  	t=a[i];
	  	a[i]=a[j];
	  	a[j]=t;
	  }
	}
	a[low]=a[j];
	a[j]=p;
	return j;
}
/****************************************************************/
int main()
{
	int i,n,a[20],ch;
	printf("\nEnter the size of array:");
					scanf("%d",&n);
					if(n>0&&n<20)
					{
			 		printf("\nEnter The value:");
					for(i=0;i<n;i++)
					scanf("%d",&a[i]);
					}
					else
					printf("\nNo space");
					
	do{
		printf("\n1.Bubblesort\n2.Insertionsort\n3.Selectionsort\n4.Quicksort\n5.Exit\n\n");
		printf("\nEnter your Choice:");
		scanf("%d",&ch);
		switch(ch)
			{
			case 1: bubblesort(a,n);
					show(a,n);
					
					break;
			case 2:
					insertion(a,n);
					show(a,n);
					
					break;
			case 3: 
					selection(a,n);
					show(a,n);
					
					break;
							
			case 4: quicksort(a,0,n-1);
			        show(a,n);
			         
					 break;		
			case 5:exit(0);
			
			default:printf("\nWrong Choice");
					break;
		}
	}while(1);
	return 0;
}
