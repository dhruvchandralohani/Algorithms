#include <iostream>
using namespace std;
int count=0;
void ImprovedInsertionSort(int A[],int n)
{
	int i,j,v;
	for(i=1;i<n;i++)
	{
		v=A[i];
		j=i;
		while(A[j-1]>v && j>0)
		{
			A[j]=A[j-1];
			j--;
			count++;
		}
		A[j]=v;
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
	ImprovedInsertionSort(A,n);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
	cout<<"\nNumber of Comparisons:"<<count;
}
