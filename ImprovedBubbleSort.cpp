#include <iostream>
using namespace std;
int count=0;
void ImprovedBubbleSort(int A[],int n)
{
	int i,j,swapped=1;
	for(i=n-1;i>=0 && swapped;i--)
	{
		swapped=0;
		for(j=0;j<=i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				count++;
				A[j]=A[j]+A[j+1];
				A[j+1]=A[j]-A[j+1];
				A[j]=A[j]-A[j+1];
				swapped=1;
			}
		}
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
	ImprovedBubbleSort(A,n);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
	cout<<"\nCount:"<<count;
}
