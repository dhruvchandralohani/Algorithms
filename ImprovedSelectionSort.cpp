#include <iostream>
using namespace std;
int count=0;
void ImprovedSelectionSort(int A[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
			{
				min=j;
				count++;
			}
		}
		temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
}
int main()
{
	int n,p,*A;
	cout<<"Enter no. of elements:";
	cin>>n;
	A=new int[n];
	cout<<"\nEnter Elements:"<<endl;
	for(p=0;p<n;p++)
		cin>>A[p];
	ImprovedSelectionSort(A,n);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
	cout<<"\nCount:"<<count;
}
